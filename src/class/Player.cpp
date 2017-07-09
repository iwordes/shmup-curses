/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:42:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 00:01:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>

Player::Player(uint16_t x, uint16_t y)
{
	this->icon = ">";
	this->w = 1;
	this->h = 1;
	this->isSolid = true;
	this->isHostile = false;

	this->x = x;
	this->y = y;

	this->hp = 3;

	this->maxTtFire = 16;
	this->maxTtMove = 2;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
}

Player::Player(const Player &)
{
	throw "Don't do that.";
}

Player::~Player() {}


void	Player::onTick(World &world)
{
	int c;

	werase(world.winHud);
	mvwprintw(world.winHud, 0, 0, ": +%u -- %.2u:%.2u (%u)", hp, this->time / 1000 / 60, this->time / 1000 % 60, this->time / 50);

	if ((c = getch()) != ERR)
	{
		if ((c == 'w' || c == 'a' || c == 's' || c == 'd') && ttMove <= 0)
		{
			ttMove = maxTtMove;
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

	}
	while (getch() != ERR);

	if (ttFire == 0)
	{
		this->onFire(world);
		ttFire = maxTtFire;
	}

	if (ttMove > 0)
		ttMove--;
	if (ttFire > 0)
		ttFire--;

	this->time += 50;
	this->score += 5;

	wrefresh(world.winHud);
}

void Player::onFire(World &world)
{
	world.addFg(new Projectile("=", x + 1, y, 2, 0, false));
}

/*
bool Player::onHit(World &, Entity &)
{
	return (--hp <= 0);
}
*/
