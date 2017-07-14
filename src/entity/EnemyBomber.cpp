/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBomber.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:04:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 20:23:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyBomber.hpp>

EnemyBomber::EnemyBomber(int16_t x, int16_t y): Enemy("<[", x, y, 2, 1)
{
	this->hp = 2;
	this->moveX = -1;
	this->maxFire = 2;
}

void EnemyBomber::onFire(World &world)
{
	world.fg2.add(new Bullet("*", x + 2, y, 0, 0));
}
