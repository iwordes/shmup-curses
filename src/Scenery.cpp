/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenery.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 01:49:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 01:54:02 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Scenery.hpp>

Scenery::Scenery(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h): Entity(icon, x, y, w, h)
{
	type = -1;
}

Scenery::Scenery(const Scenery &copy)
{
	*this = copy;
}

Scenery::~Scenery() {}

const Scenery &Scenery::operator=(const Scenery &rhs):
{
	Entity::operator=(rhs);
	return (*this);
}

// =====================================================================================================================

bool Scenery::onHit(World &, Entity &) { return false; }
