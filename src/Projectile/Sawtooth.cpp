/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sawtooth.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:30:01 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 22:36:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Sawtooth.hpp>
#include <World.hpp>
#include <Enemy.hpp>

Sawtooth::Sawtooth(uint8_t type, const char *icon, int16_t x, int16_t y, int8_t d): Projectile(type, icon, x, y, 1, 0)
{
	this->d = d;
	this->ttTurn = 0;
}

Sawtooth::Sawtooth(const Sawtooth &) {}
Sawtooth::~Sawtooth() {}
Sawtooth &Sawtooth::operator=(const Sawtooth &) { return *this; }

void Sawtooth::onTick(World &)
{
	x += 1;
	if (ttTurn <= 4)
		y += d;
	else if (ttTurn <= 12)
		y -= d;
	else if (ttTurn <= 16)
		y += d;
	else
		ttTurn = 0;
	ttTurn++;
}

// Yes this is hacky shit.
bool Sawtooth::onHit(World &world, Entity &by)
{
	if (by.isEnemy())
		world.fg[0]->score += ((Enemy*)&by)->score;
	else if (by.isBullet())
		world.fg[0]->score += 100;
	return (true);
}
