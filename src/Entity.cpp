/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:17:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 20:40:00 by iwordes          ###   ########.fr       */
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

bool Entity::onHit(World &, Entity &)
{
	return (--hp <= 0);
}
