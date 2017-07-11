/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:17:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/11 12:56:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Entity.hpp>
#include <World.hpp>

Entity::Entity(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h)
{
	this->icon = icon;
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;

	this->score = 0;
}

Entity::Entity(const Entity &)
{
	throw "Don't do that.";
}

Entity::~Entity() {}

const Entity &Entity::operator=(const Entity &rhs)
{
	this->icon = rhs.icon;
	this->w = rhs.w;
	this->h = rhs.h;
	this->x = rhs.x;
	this->y = rhs.y;
	this->score = 0;
	return (*this);
}

// =====================================================================================================================

bool Entity::isBullet() { return false; }
bool Entity::isEnemy() { return false; }
bool Entity::isPlayer() { return false; }

void Entity::onTick(World &) {}
bool Entity::onHit(World &, Entity &) { return true; }
