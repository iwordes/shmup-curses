/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:28:52 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:19:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>

Enemy::Enemy(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h): Entity(icon, x, y, w, h)
{
	this->moveX = 0;
	this->moveY = 0;
	this->ttx = moveX;
	this->tty = moveY;

	this->maxFire = 1;
	this->ttFire = maxFire;
}

void Enemy::onTick(World &world)
{
	{
		int8_t dx = (moveX > 0) ? 1 : -1;
		int8_t dy = (moveY > 0) ? 1 : -1;

		if (moveX && ttx == 0)
		{
			ttx = moveX;
			x += dx;
		}
		if (moveY && tty == 0)
		{
			tty = moveY;
			y += dy;
		}

		if (moveX)
			ttx -= dx;
		if (moveY)
			tty -= dy;
	}
	if (ttFire-- <= 0)
	{
		onFire(world);
		ttFire = maxFire;
	}
}
