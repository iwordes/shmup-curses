/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:42:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 22:49:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>

Player::Player(uint16_t x, uint16_t y)
{
	this->icon = ">";
	this->w = 1;
	this->h = 1;

	this->x = x;
	this->y = y;

	this->maxTtFire = 10;
	this->maxTtMove = 5;
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
	mvwprintw(world.winHud, 0, 0, ": %hhu", ttMove);

	if ((c = getch()) != ERR)
	{
		wprintw(world.winHud, "+%c", (char)c);
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

void Player::onFire(World &)
{
	/*world.addFg(new Projectile(
		// ...
	));*/
}

/*
bool Player::onHit(World &, Entity &)
{
	return (--hp <= 0);
}
*/
