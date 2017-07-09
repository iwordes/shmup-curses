/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBomber.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:22:15 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 14:32:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyBomber.hpp>

EnemyBomber::EnemyBomber(int16_t x, int16_t y): Enemy("<[", x, y, 2, 1)
{
	this->maxTtFire = 40;
	this->maxTtMove = 8;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->score = 300;

	this->payload = Projectile(type, "*", 0, 0, -20);
}

EnemyBomber::EnemyBomber(const EnemyBomber &copy)
{
	*this = copy;
}

EnemyBomber::~EnemyBomber() {}

EnemyBomber &EnemyBomber::operator=(const EnemyBomber &rhs)
{
	Enemy::operator=(rhs);
	this->payload = rhs.payload;
	return (*this);
}

void EnemyBomber::onFire(World &world)
{
	payload.x = x + 2;
	payload.y = y;
	world.addFg(new Projectile(payload));
}
