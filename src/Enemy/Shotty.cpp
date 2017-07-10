/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shotty.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:41:17 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 23:27:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyShotty.hpp>

EnemyShotty::EnemyShotty(int16_t x, int16_t y): Enemy("D==;", x, y, 4, 1)
{
	this->maxTtFire = 40;
	this->maxTtMove = 8;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;

	this->score = 500;
}

EnemyShotty::EnemyShotty(const EnemyShotty &) {}
EnemyShotty::~EnemyShotty() {}

EnemyShotty &EnemyShotty::operator=(const EnemyShotty &) { return *this; }

void EnemyShotty::onFire(World &world)
{
	world.addFg(new Projectile(type, "\\", x - 1, y - 1, -2, -2));
	world.addFg(new Projectile(type, "-",  x - 1, y,     -4,  0));
	world.addFg(new Projectile(type, "/",  x - 1, y + 1, -2,  2));
}
