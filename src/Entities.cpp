/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 12:57:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/15 18:14:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Entities.hpp>
#include <Entity.hpp>
#include <World.hpp>

Entities::Entities()
{
	this->arr = new Entity*[8]();
	this->len = 8;

	this->effect = 0;

	this->collider = NULL;
	this->col_len = 0;
}

Entities::~Entities()
{
	for (uint32_t i = 0; i < len; i++)
		delete arr[i];
	delete collider;
	delete arr;
}

// =====================================================================================================================

void Entities::add(Entity *ent)
{
	for (uint32_t i = 0; i < len; i++)
		if (arr[i] == NULL)
		{
			arr[i] = ent;
			return;
		}

	Entity **tmp = new Entity*[len * 2];

	for (uint32_t i = 0; i < len; i++)
		tmp[i] = arr[i];
	for (uint32_t i = len; i < len * 2; i++)
		tmp[i] = NULL;
	tmp[len] = ent;

	delete arr;
	arr = tmp;
	len *= 2;
}

void Entities::tick(World &world)
{
	for (uint32_t i = 0; i < len; i++)
	{
		if (arr[i] == NULL || _doCull(world, i) || _doCollide(world, i))
			continue;
		arr[i]->onTick(world);
	}
}

void Entities::draw(World &world)
{
	for (uint32_t i = 0; i < len; i++)
	{
		if (arr[i] == NULL)
			continue;
		wattron(world.window, effect);
		arr[i]->onDraw(world);
		wattroff(world.window, effect);
	}
}

// =====================================================================================================================

static inline bool doesCollide(const Entity &e1, const Entity &e2)
{
	return (
		(
			e1.x < e2.x + e2.w && // Le1 < Re2 &&
			e1.x + e1.w > e2.x    // Re1 > Le2
		) &&
		(
			e1.y < e2.y + e2.h && // Te1 < Be2 &&
			e1.y + e1.h > e2.y    // Be1 > Te2
		)
	);
}

bool Entities::collide(World &world, Entity &with)
{
	for (uint32_t i = 0; i < len; i++)
	{
		if (arr[i] == NULL)
			continue;
		if (doesCollide(with, *arr[i]))
		{
			bool d1 = with.onHit(world, *arr[i]);
			bool d2 = arr[i]->onHit(world, with);

			if (d2)
			{
				delete arr[i];
				arr[i] = NULL;
			}
			if (d1)
				return true;
		}
	}
	return false;
}

// =====================================================================================================================

void Entities::addCollider(Entities &col)
{
	Entities **tmp = new Entities*[col_len + 1]();

	for (uint16_t i = 0; i < col_len; i++)
		tmp[i] = collider[i];

	delete collider;
	collider = tmp;

	collider[col_len++] = &col;
}

void Entities::setEffect(int effect)
{
	this->effect = effect;
}

void Entities::clear(uint32_t i)
{
	for (; i < len; i++)
	{
		delete arr[i];
		arr[i] = NULL;
	}
}

// =====================================================================================================================

Entity *Entities::operator[](uint32_t i) const
{
	return arr[i];
}

// =====================================================================================================================

bool Entities::_doCull(World &world, uint32_t i)
{
	Entity &e = *arr[i];

	bool cull = !(
		e.x < (int)world.w && // Lent < Rwin &&
		e.x + e.w > 0         // Rent > Lwin
	) &&
	(
		e.y < (int)world.h && // Tent < Bwin &&
		e.y + e.h > 0         // Bent > Twin
	);

	if (cull)
	{
		delete arr[i];
		arr[i] = NULL;
	}
	return (cull);
}

bool Entities::_doCollide(World &world, uint32_t i)
{
	for (uint16_t c = 0; c < col_len; c++)
		if (collider[c]->collide(world, *arr[i]))
		{
			delete arr[i];
			arr[i] = NULL;
			return true;
		}
	return false;
}
