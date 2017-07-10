/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Orb.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:32:59 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 20:17:56 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Orb.hpp>

Orb::Orb(int16_t x, int16_t y, int8_t tx, int8_t ty)
{
	this->x = x;
	this->y = y;



	this->icon =
    " .-.
     (   )
	  '-' "
	this->w = 6;
	this->h = 3;
}

Orb::Orb(const Orb &copy)
{
	throw "Don't do that.";
}

Orb::~Orb() {}

Orb::Orb::operator=(const Orb &rhs)
{
	throw "Don't do that.";
}
