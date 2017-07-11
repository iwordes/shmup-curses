/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:42:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/11 14:48:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Player.hpp>
#include <PlayerBOB.hpp>
#include <Sawtooth.hpp>

Player::Player(uint16_t x, uint16_t y): Entity(">", x, y, 1, 1)
{
	this->type = 0;

	this->maxTtFire = 15;
	this->maxTtMove = 4;
	this->ttFire = maxTtFire;
	this->ttMove = maxTtMove;
	this->ttHit = 0;
	this->lvl = 0;
	this->hp = 3;

	this->time = 0;
	this->score = 0;
	this->scoreToLvl = 8000;
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
	mvwprintw(world.winHud, 0, 0, " Lv.%u -- HP: %u -- Shoot: %u -- Move: %u", lvl, hp, maxTtFire, maxTtMove);
	mvwprintw(world.winHud, 1, 0, " Score: %u -- Time: %.2u:%.2u -- Wave %u in T-%.2u:%.2u.%.3u",
		score,
		this->time / 1000 / 60, this->time / 1000 % 60,
		world.wave + 1, world.ttWave * 50 / 1000 / 60, world.ttWave * 50 / 1000 % 60, world.ttWave * 50 % 1000);

	wprintw(world.winHud, " :: B%u", world.behind);

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

		scoreToLvl += 8000;
		scoreToLvl += lvl * 2000;
	}
}

void Player::onFire(World &world)
{

	if (lvl >= 3)
	{
		world.addFg(new PlayerBullet("/", x + 1, y - 1, 1, -6));
		world.addFg(new PlayerBullet("\\", x + 1, y + 1, 1, 6));
	}
	if (lvl >= 6)
		world.addFg(new PlayerBOB(x + 1, y));
	else
		world.addFg(new PlayerBullet("=", x + 1, y, 1, 0));
	if (lvl >= 10)
	{
		// world.addFg(new PlayerBullet(type, "[", x + 3, y - 3, 1, 0));
		// world.addFg(new PlayerBullet(type, "[", x + 3, y + 3, 1, 0));
		world.addFg(new Sawtooth(type, "x", x - 1, y, 1));
		world.addFg(new Sawtooth(type, "x", x - 1, y, 1));
	}
}

bool Player::onHit(World &, Entity &)
{
	if (ttHit > 0)
		return false;
	ttHit = 10;
	return (hp-- <= 0);
}
