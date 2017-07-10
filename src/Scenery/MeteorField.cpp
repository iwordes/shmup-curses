/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeteorField.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:32:59 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 19:35:02 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MeteorField.hpp>

MeteorField::MeteorField(int16_t x, int16_t y, int8_t tx, int8_t ty)
{
	this->x = x;
	this->y = y;



	this->icon = ".:*~*:.";
	this->w = 7;
	this->h = 1;
}

MeteorField::MeteorField(const MeteorField &copy)
{
	throw "Don't do that.";
}

MeteorField::~MeteorField() {}

MeteorField &MeteorField::operator=(const MeteorField &rhs)
{
	throw "Don't do that.";
}
