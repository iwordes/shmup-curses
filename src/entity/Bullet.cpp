/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:24:26 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:08:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(const char *icon, int16_t x, int16_t y, int16_t ttx, int16_t tty): Entity(icon, x, y)
{
	this->moveX = ttx;
	this->moveY = tty;
	this->ttx = ttx;
	this->tty = tty;

	this->score = 100;
}

void Bullet::onTick(World &)
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
