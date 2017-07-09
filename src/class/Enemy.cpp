/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:42:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 01:15:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>

Enemy::Enemy(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h)
{
	this->icon = icon;
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;

	this->score = 100;
	this->isSolid = true;
	this->isHostile = true;

	this->maxTtFire = 20;
	this->maxTtMove = 20;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
}

Enemy::Enemy(const Enemy &copy)
{
	*this = copy;
}

Enemy::~Enemy() {}

const Enemy &Enemy::operator=(const Enemy &rhs)
{
	this->icon = rhs.icon;
	this->w = rhs.w;
	this->h = rhs.h;
	this->x = rhs.x;
	this->y = rhs.y;

	this->score = rhs.score;
	this->isSolid = rhs.isSolid;
	this->isHostile = rhs.isHostile;

	this->maxTtFire = rhs.maxTtFire;
	this->maxTtMove = rhs.maxTtMove;
	this->ttFire = rhs.ttFire;
	this->ttMove = rhs.ttMove;

	return *this;
}

// =====================================================================================================================

void Enemy::onTick(World &world)
{
	if (this->ttMove <= 0)
	{
		x -= 1;
		ttMove = maxTtMove;
	}

	if (this->ttFire <= 0)
	{
		world.addFg(new Projectile("c", x - 1, y, -4));
		ttFire = maxTtMove;
	}

	ttFire--;
	ttMove--;
}
