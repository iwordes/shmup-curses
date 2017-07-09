/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:42:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 14:51:08 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>

Player::Player(uint16_t x, uint16_t y): Entity(">", x, y, 1, 1)
{
	this->type = 0;

	this->maxTtFire = 12;
	this->maxTtMove = 4;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->ttHit = 0;
	this->lvl = 0;
	this->hp = 2;

	this->scoreToLvl = 6000;
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

bool Player::isPlayer() { return true; }

void	Player::onTick(World &world)
{
	int c;

	tryLevel();

	werase(world.winHud);
	mvwprintw(world.winHud, 0, 0, " Lv.%u -- HP: %u -- Fi: %u -- Mv: %u", lvl, hp + 1, maxTtFire, maxTtMove);
	mvwprintw(world.winHud, 1, 0, " Score: %u -- Time: %.2u:%.2u -- Wave %u: T-%.2u:%.2u.%.3u",
		score,
		this->time / 1000 / 60, this->time / 1000 % 60,
		world.wave + 1, world.ttWave * 50 / 1000 / 60, world.ttWave * 50 / 1000 % 60, world.ttWave * 50 % 1000);
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

void Player::tryLevel()
{
	if (score > scoreToLvl)
	{
		if (lvl % 3 == 0 && maxTtMove > 2)
			maxTtMove--;
		if (lvl & 1 && maxTtFire > 3)
			maxTtFire--;
		if (lvl & 2)
			hp++;

		lvl++;

		scoreToLvl += 5000;
		scoreToLvl += lvl * 1000;
	}
}

void Player::onFire(World &world)
{
	world.addFg(new PlayerBullet("=", x + 1, y, 1, 0));
	if (lvl >= 3)
	{
		world.addFg(new PlayerBullet("/", x + 1, y - 1, 1, -6));
		world.addFg(new PlayerBullet("\\", x + 1, y + 1, 1, 6));
	}
}

bool Player::onHit(World &, Entity &)
{
	if (ttHit > 0)
		return false;
	ttHit = 10;
	return (hp-- <= 0);
}
