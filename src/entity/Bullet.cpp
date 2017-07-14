/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:24:26 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 16:41:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(const char *icon, int16_t x, int16_t y, int16_t ttx, int16_t tty): Entity(icon, x, y)
{
	this->maxTtx = ttx;
	this->maxTty = tty;
	this->ttx = ttx;
	this->tty = tty;

	this->score = 100;
}

void Bullet::onTick(World &)
{
	int8_t dx = 0;
	int8_t dy = 0;

	if (maxTtx != 0)
		dx = (maxTtx > 0) ? 1 : -1;
	if (maxTty != 0)
		dy = (maxTty > 0) ? 1 : -1;

	if (ttx == 0)
	{
		ttx = maxTtx;
		x += dx;
	}
	if (tty == 0)
	{
		tty = maxTty;
		y += dy;
	}

	ttx -= dx;
	tty -= dy;
}
