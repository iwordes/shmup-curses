/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:34:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 23:27:37 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Projectile.hpp>

Projectile::Projectile(const char *icon, int16_t x, int16_t y, int8_t tx, int8_t ty, bool isHostile)
{
	this->icon = icon;
	this->w = 1;
	this->h = 1;
	this->x = x;
	this->y = y;

	this->isSolid = true;
	this->isHostile = isHostile;

	this->mttx = tx;
	this->mtty = ty;
	this->ttx = 0;
	this->tty = 0;
}

Projectile::Projectile(const Projectile &copy)
{
	*this = copy;
}

Projectile::~Projectile() {}

const Projectile &Projectile::operator=(const Projectile &rhs)
{
	this->icon = rhs.icon;
	this->w = rhs.w;
	this->h = rhs.h;
	this->x = rhs.x;
	this->y = rhs.y;

	this->isSolid = rhs.isSolid;
	this->isHostile = rhs.isHostile;

	this->mttx = rhs.mttx;
	this->mtty = rhs.mtty;
	this->ttx = rhs.ttx;
	this->tty = rhs.tty;
	return (*this);
}

// =====================================================================================================================

void Projectile::onTick(World &)
{
	int8_t dx = 0;
	int8_t dy = 0;

	if (mttx != 0)
		dx = (mttx > 0) ? 1 : -1;
	if (mtty != 0)
		dy = (mtty > 0) ? 1 : -1;

	if (ttx == 0)
	{
		ttx = mttx;
		x += dx;
	}
	if (tty == 0)
	{
		tty = mtty;
		y += dy;
	}

	ttx -= dx;
	tty -= dy;
}
