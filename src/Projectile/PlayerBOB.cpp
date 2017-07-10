/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerBOB.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:00:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 22:49:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PlayerBOB.hpp>

PlayerBOB::PlayerBOB(int16_t x, int16_t y)
{
	this->icon = "=>";
	this->x = x;
	this->y = y;
	this->w = 2;
	this->h = 1;

	this->mttx = 1;
	this->mtty = 0;
	this->ttx = mttx;
	this->tty = mtty;

	this->hp = 3;

	this->maxTtSplit = 20;
	this->ttSplit = maxTtSplit;
}

PlayerBOB::PlayerBOB(const PlayerBOB &) {}
PlayerBOB::~PlayerBOB() {}
PlayerBOB &PlayerBOB::operator=(const PlayerBOB &) { return *this; }

bool PlayerBOB::onHit(World &world, Entity &by)
{
	PlayerBullet::onHit(world, by);
	return (hp-- <= 0);
}
