/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Twirly.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:51:06 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 23:27:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyTwirly.hpp>

EnemyTwirly::EnemyTwirly(int16_t x, int16_t y): Enemy("@", x, y, 1, 1)
{
	this->maxTtFire = 2;
	this->maxTtMove = 10;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;

	this->side = 0;
	this->score = 800;
}

EnemyTwirly::EnemyTwirly(const EnemyTwirly &) {}
EnemyTwirly::~EnemyTwirly() {}
EnemyTwirly &EnemyTwirly::operator=(const EnemyTwirly &) { return *this; }

void EnemyTwirly::onFire(World &world)
{
	if (ttFire == 0)
	{
		switch (side)
		{
			case 0: world.addFg(new Projectile(type, "|", x, y + 1, 0, 3));        break; // S
			case 1: world.addFg(new Projectile(type, "/", x - 1, y + 1, -3, 3));   break; // SW
			case 2: world.addFg(new Projectile(type, "-", x - 1, y, -3, 0));       break; // W
			case 3: world.addFg(new Projectile(type, "\\", x - 1, y - 1, -3, -3)); break; // NW
			case 4: world.addFg(new Projectile(type, "|", x, y - 1, 0, -3));       break; // N
			case 5: world.addFg(new Projectile(type, "/", x + 1, y - 1, 3, -3));   break; // NE
			case 6: world.addFg(new Projectile(type, "-", x + 1, y, 3, 0));        break; // E
			case 7: world.addFg(new Projectile(type, "\\", x + 1, y + 1, 3, 3));   break; // SE
		}
		side = (side + 1) % 8;
		ttFire = maxTtFire;
	}
	ttFire--;
}
