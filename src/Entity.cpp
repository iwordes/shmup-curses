/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:17:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 15:18:04 by iwordes          ###   ########.fr       */
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
}

Entity::~Entity() {}

// =====================================================================================================================

void Entity::onTick(World &) {}
bool Entity::onHit(World &, Entity &) { return true; }
