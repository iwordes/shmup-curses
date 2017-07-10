/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:59:51 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 18:14:25 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyBat.hpp>

EnemyBat::EnemyBat(int16_t x, int16_t y): Enemy("-^-", x, y, 3, 1)
{
	this->maxTtFire = 40;
	this->maxTtMove = 8;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->score = 300;
	this->down = 1;

}

EnemyBat::EnemyBat(const EnemyBat &copy)
{
	*this = copy;
}

EnemyBat::~EnemyBat() {}

EnemyBat &EnemyBat::operator=(const EnemyBat &rhs)
{
	Enemy::operator=(rhs);
	this->payload = rhs.payload;
	return (*this);
}

void EnemyBat::onTick(World &world)
{

	if (this->ttMove <= 0 && y > 0)
	{
		ttMove = maxTtMove;
		x -= 1;
		if (down)
		{
			y +=1;
			down = 0;
		}
		else
		{
			y -=1;
			down = 1;
		}
	}

	if (this->ttFire <= 0)
	{
		this->onFire(world);
		ttFire = maxTtFire;
	}

	ttFire--;
	ttMove--;
}
