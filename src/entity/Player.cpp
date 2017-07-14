/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:33:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 19:31:59 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>
#include <BulletPlayer.hpp>

Player::Player(int16_t x, int16_t y): Entity(">", x, y)
{
	this->toLvl = 10000;
	this->lvl = 1;
	this->hp = 3;

	this->maxFire = 20;
	this->maxMove = 3;
	this->ttFire = maxFire;
	this->ttMove = maxMove;
}

void Player::onTick(World &world)
{
	onMove(world);
	onFire(world);
	onLevel();
	drawStats(world);
}

void Player::onFire(World &world)
{
	if (ttFire-- <= 0)
	{
		world.fg1.add(new BulletPlayer("-", x + 1, y, 1, 0, 0));
		ttFire = maxFire;
	}
}

void Player::onMove(World &world)
{
	int c;

	if ((c = getch()) != ERR)
	{
		if ((c == 'w' || c == 'a' || c == 's' || c == 'd') && ttMove <= 0)
		{
			ttMove = maxMove;
			if (c == 'w' && y > 0)
				y -= 1;
			else if (c == 'a' && x > 0)
				x -= 1;
			else if (c == 's' && y < (int)world.h - 1)
				y += 1;
			else if (c == 'd' && x < (int)world.w - 1)
				x += 1;
			else
				ttMove = 0;
		}
		while (getch() != ERR);
	}

	if (ttMove > 0)
		ttMove--;
}

void Player::onLevel()
{
	// ...
}

void Player::drawStats(World &)
{
	// werase(world.hud);
	// ...
	// wrefresh(world.hud);
}
