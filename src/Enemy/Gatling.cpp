/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gatling.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:26:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 18:52:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyGatling.hpp>

EnemyGatling::EnemyGatling(int16_t x, int16_t y): Enemy("}=", x, y, 2, 1)
{
	this->score = 400;
	this->ttFire = 3;
	this->ttMove = 5;
	this->tt = 0;
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

	if (tt <= 60)
		onMove(world);
	else if (tt <= 100)
		onFire(world);
	else if (tt == 160)
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

	int tx = -1 - (rng() % 10);
	int ty = -6 - (rng() % 5);

	if (tmp == 0)
		world.addFg(new Projectile(type, "-", x - 1, y - 1, tx, ty));
	else if (tmp == 1)
		world.addFg(new Projectile(type, "-", x - 1, y,     tx, 0));
	else if (tmp == 2)
		world.addFg(new Projectile(type, "-", x - 1, y + 1, tx, -ty));
	else
		world.addFg(new Projectile(type, "-", x - 1, y,     tx, 0));
}
