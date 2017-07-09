/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyOcto.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:36:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 13:25:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyOcto.hpp>

EnemyOcto::EnemyOcto(int16_t x, int16_t y): Enemy("B", x, y, 1, 1)
{
	this->maxTtFire = 10;
	this->maxTtMove = 10;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;

	this->ff = 0;
}

EnemyOcto::EnemyOcto(const EnemyOcto &copy): Enemy(copy) {}

EnemyOcto::~EnemyOcto() {}

EnemyOcto &EnemyOcto::operator=(const EnemyOcto &rhs)
{
	Enemy::operator=(rhs);
	return (*this);
}

void EnemyOcto::onFire(World &world)
{
	if (ff)
	{
		world.addFg(new Projectile(type, "\\", x - 1, y - 1, -3, -3)); // NW
		world.addFg(new Projectile(type, "/", x + 1, y - 1, 3, -3));   // NE
		world.addFg(new Projectile(type, "\\", x + 1, y + 1, 3, 3));   // SE
		world.addFg(new Projectile(type, "/", x - 1, y + 1, -3, 3));   // SW
	}
	else
	{
		world.addFg(new Projectile(type, "|", x, y - 1, 0, -3)); // N
		world.addFg(new Projectile(type, "-", x + 1, y, 3, 0));  // E
		world.addFg(new Projectile(type, "|", x, y + 1, 0, 3));  // S
		world.addFg(new Projectile(type, "-", x - 1, y, -3, 0)); // W
	}
	ff = !ff;
}
