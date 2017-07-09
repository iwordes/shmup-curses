/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:42:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 12:52:53 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>

Player::Player(uint16_t x, uint16_t y): Entity(">", x, y, 1, 1)
{
	this->type = 0;

	this->maxTtFire = 12;
	this->maxTtMove = 2;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->ttHit = 0;
	this->hp = 3;
}

Player::Player(const Player &)
{
	throw "Don't do that.";
}

Player::~Player() {}

const Player &Player::operator=(const Player &)
{
	throw "Don't do that.";
}

// =====================================================================================================================

void	Player::onTick(World &world)
{
	int c;

	werase(world.winHud);
	mvwprintw(world.winHud, 0, 0, " %u lives -- %.2u:%.2u (%u) -- Wave %u -- T-%.2u:%.2u.%.3u -- Score: %u",
		hp,
		this->time / 1000 / 60, this->time / 1000 % 60, this->time / 50,
		world.wave, world.ttWave * 50 / 1000 / 60, world.ttWave * 50 / 1000 % 60, world.ttWave * 50 % 1000,
		score);
	wrefresh(world.winHud);

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
		while (getch() != ERR);
	}

	if (ttFire == 0)
	{
		this->onFire(world);
		ttFire = maxTtFire;
	}

	if (ttMove > 0)
		ttMove--;
	if (ttFire > 0)
		ttFire--;
	if (ttHit > 0)
		ttHit--;

	this->time += 50;
	this->score += 5;
}

void Player::onFire(World &world)
{
	world.addFg(new Projectile(type, "=", x + 1, y, 1));
}

bool Player::onHit(World &, Entity &)
{
	if (ttHit > 0)
		return false;
	ttHit = 10;
	return (hp-- <= 0);
}
