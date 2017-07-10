/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gatling.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:26:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 23:27:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyGatling.hpp>

EnemyGatling::EnemyGatling(int16_t x, int16_t y): Enemy("}=", x, y, 2, 1)
{
	this->score = 400;
	this->ttFire = 3;
	this->ttMove = 2;
	this->tt = 0;

	this->score = 1600;
}

EnemyGatling::EnemyGatling(const EnemyGatling &copy)
{
	*this = copy;
}

EnemyGatling::~EnemyGatling() {}

EnemyGatling &EnemyGatling::operator=(const EnemyGatling &rhs)
{
	Enemy::operator=(rhs);
	return *this;
}

void EnemyGatling::onTick(World &world)
{
	//   }=
	// 1. Shoot for N ticks
	// 2. Move forward for N ticks
	// 3. Wait for N ticks

	if (tt <= 20)
		onMove(world);
	else if (tt <= 60)
		onFire(world);
	else if (tt == 100)
		tt = -1;
	tt++;
}

void EnemyGatling::onMove(World &)
{
	if (tt % ttMove == 0)
		x -= 1;
}

static std::random_device rd;
static std::mt19937 rng(rd());

void EnemyGatling::onFire(World &world)
{
	int tmp = tt % 4;

	int tx = -1 - (rng() % 3);
	int ty = -10 - (rng() % 3);

	if (tmp == 0)
		world.addFg(new Projectile(type, "-", x - 1, y - 1, tx, ty));
	else if (tmp == 1)
		world.addFg(new Projectile(type, "-", x - 1, y,     tx, 0));
	else if (tmp == 2)
		world.addFg(new Projectile(type, "-", x - 1, y + 1, tx, -ty));
	else
		world.addFg(new Projectile(type, "-", x - 1, y,     tx, 0));
}
