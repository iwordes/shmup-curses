/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 14:34:36 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 20:00:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Projectile.hpp>

void Projectile::Projectile(const char *icon, int8_t tx, int8_t ty)
{
	this->icon = icon;
	this->w = 1;
	this->h = 1;

	this->mttx = tx;
	this->mtty = ty;
	this->ttx = tx;
	this->tty = ty;
}

void Projectile::Projectile(const Projectile &copy)
{
	*this = copy;
}

void Projectile::~Projectile() {}

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
}

// =====================================================================================================================

virtual void Projection::onTick(World &world)
{
	int8_t dx = (mttx > 0) ? 1 : -1;
	int8_t dy = (mtty > 0) ? 1 : -1

	if (ttx == mttx)
	{
		ttx = mttx;
		x += dx;
	}
	if (tty == mtty)
	{
		tty = mtty;
		y += dy;
	}

	ttx -= dx;
	tty -= dy;
}
