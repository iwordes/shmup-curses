/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Spiky.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:50:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 23:27:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemySpiky.hpp>

EnemySpiky::EnemySpiky(int16_t x, int16_t y): Enemy("X", x, y, 1, 1)
{
	this->maxTtFire = 8;
	this->maxTtMove = 1;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->ff = false;

	this->score = 1000;
}

EnemySpiky::EnemySpiky(const EnemySpiky &) {}
EnemySpiky::~EnemySpiky() {}

EnemySpiky &EnemySpiky::operator=(const EnemySpiky &) { return *this; }

void EnemySpiky::onFire(World &world)
{
	world.addFg(new Projectile(type, "\\", x - 1, y - 1, -3, -3)); // NW
	world.addFg(new Projectile(type, "/", x + 1, y - 1, 3, -3));   // NE
	world.addFg(new Projectile(type, "\\", x + 1, y + 1, 3, 3));   // SE
	world.addFg(new Projectile(type, "/", x - 1, y + 1, -3, 3));   // SW
	world.addFg(new Projectile(type, "|", x, y - 1, 0, -3));       // N
	world.addFg(new Projectile(type, "-", x + 1, y, 3, 0));        // E
	world.addFg(new Projectile(type, "|", x, y + 1, 0, 3));        // S
	world.addFg(new Projectile(type, "-", x - 1, y, -3, 0));       // W
}
