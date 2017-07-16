/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:17:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/15 18:11:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Entity.hpp>
#include <World.hpp>

Entity::Entity(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h)
{
	this->icon = icon;
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;

	this->score = 0;
	this->type = 0;
	this->hp = 1;
}

#define BOUND_Y (y + iy >= 0 && y + iy < (int)world.h)
#define BOUND_X (x + ix >= 0 && x + ix < (int)world.w)

void Entity::onDraw(World &world)
{
	for (int16_t iy = 0; iy < h; iy++) if (BOUND_Y)
	{
		for (int16_t ix = 0; ix < w; ix++) if (BOUND_X)
		{
			mvwaddch(
				world.window,
				y + iy,
				x + ix,
				icon[iy * w + ix]
			);
		}
	}
}

bool Entity::onHit(World &, Entity &)
{
	return (--hp <= 0);
}
