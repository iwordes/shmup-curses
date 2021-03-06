/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBomber.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:04:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/15 21:09:14 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyBomber.hpp>

EnemyBomber::EnemyBomber(int16_t x, int16_t y): Enemy("<[", x, y, 2, 1)
{
	this->hp = 2;
	this->moveX = -2;
	this->maxFire = 13;
	this->score = 2000;
}

void EnemyBomber::onFire(World &world)
{
	world.fg2.add(new Bullet("*", x + 2, y, -20, 0));
}
