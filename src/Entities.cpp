/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 12:57:45 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 14:53:54 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Entities.hpp>

Entities::Entities()
{
	this->arr = new Entity*[8]();
	this->len = 8;

	this->effect = 0;

	this->collider = NULL;
	this->len = 0;
}

Entities::~Entities()
{
	for (uint32_t i = 0; i < len; i++)
		delete arr[i];
	delete collider;
	delete arr;
}

// =====================================================================================================================

void Entities::add(Entity *entity)
{
	for (uint32_t i = 1; i < len; i++)
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
		if (arr[i] == NULL || _doCull(i) || _doCollide(i))
			continue;
		arr[i]->onTick(world);
	}
}

#define BOUND_Y (e.y + y >= 0 && e.y + y < (int)world.h)
#define BOUND_X (e.x + x >= 0 && e.x + x < (int)world.w)

void Entities::draw(World &world)
{
	for (uint32_t i = 0; i < len; i++)
	{
		if (arr[i] == NULL)
			continue;

		Entity &e = *arr[i];

		for (int16_t y = 0; y < e.h; y++) if (BOUND_Y)
		{
			for (int16_t x = 0; x < e.w; x++) if (BOUND_X)
			{
				mvwaddch(
					world.window,
					e.y + y,
					e.x + x,
					e.icon[y * e.w + x] | effect
				);
			}
		}
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
		if (doesCollide(with, *arr[i]))
		{
			bool d1 = with->onHit(world, *arr[i]);
			bool d2 = arr[i]->onHit(world, with);

			if (d2)
			{
				delete arr[i];
				arr[i] = NULL;
			}
			return d1;
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

Entity *Entities::operator[](uint32_t i)
{
	return arr[i];
}

// =====================================================================================================================

bool Entities::_doCull(World &world, Entity &e)
{
	return !(
		e.x < (int)world.w && // Lent < Rwin &&
		e.x + e.w > 0         // Rent > Lwin
	) &&
	(
		e.y < (int)world.h && // Tent < Bwin &&
		e.y + e.h > 0         // Bent > Twin
	);
}

bool Entities::_doCollide(World &world, uint16_t i)
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
