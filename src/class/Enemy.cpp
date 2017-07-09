/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:42:12 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 12:49:52 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>

Enemy::Enemy(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h): Entity(icon, x, y, w, h)
{
	this->type = 1;

	this->maxTtFire = 60;
	this->maxTtMove = 20;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->score = 100;
}

Enemy::Enemy(const Enemy &copy)
{
	*this = copy;
}

Enemy::~Enemy() {}

const Enemy &Enemy::operator=(const Enemy &rhs)
{
	Entity::operator=(rhs);
	this->maxTtFire = rhs.maxTtFire;
	this->maxTtMove = rhs.maxTtMove;
	this->ttFire = rhs.ttFire;
	this->ttMove = rhs.ttMove;
	this->score = rhs.score;
	return *this;
}

// =====================================================================================================================

void Enemy::onTick(World &world)
{
	if (this->ttMove <= 0)
	{
		ttMove = maxTtMove;
		x -= 1;
	}

	if (this->ttFire <= 0)
	{
		this->onFire(world);
		ttFire = maxTtFire;
	}

	ttFire--;
	ttMove--;
}

void Enemy::onFire(World &) {}
