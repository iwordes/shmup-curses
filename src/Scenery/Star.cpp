/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:32:59 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 20:15:58 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Star.hpp>

Star::Star(int16_t x, int16_t y, int8_t tx, int8_t ty)
{
	this->x = x;
	this->y = y;



	this->icon =
    "**"
	this->w = 2;
	this->h = 2;
}

Star::Star(const Star &copy)
{
	throw "Don't do that.";
}

Star::~Star() {}

Star::Star::operator=(const Star &rhs)
{
	throw "Don't do that.";
}
