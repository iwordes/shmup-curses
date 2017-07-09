/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:52:37 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 16:11:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SceneryAsteroid1.hpp>

SceneryAsteroid1::SceneryAsteroid1(int16_t x, int16_t y, int8_t tx, int8_t ty)
{
	this->x = x;
	this->y = y;



	this->icon =
	" ####   "
	"########"
	"## # ###"
	"  ####  ";
	this->w = 8;
	this->h = 4;
}

SceneryAsteroid1::SceneryAstroid1(const SceneryAstroid1 &copy)
{
	throw "Don't do that.";
}

SceneryAstroid1::~SceneryAstroid1() {}

SceneryAstroid1 &SceneryAstroid1::operator=(const SceneryAstroid1 &rhs)
{
	throw "Don't do that.";
}
