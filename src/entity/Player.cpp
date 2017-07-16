/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:33:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/16 09:43:03 by iwordes          ###   ########.fr       */
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

	this->ttHit = 0;

	this->tick = 0;
}

void Player::onTick(World &world)
{
	onMove(world);
	if (ttFire-- <= 0)
		onFire(world);
	if (score >= toLvl)
		onLevel();
	drawStats(world);

	tick += 1;
}

void Player::onFire(World &world)
{
	if (lvl <= 3)
		world.fg1.add(new BulletPlayer("-", x + 1, y, 1, 0, 1));
	else if (lvl <= 6)
		world.fg1.add(new BulletPlayer("=", x + 1, y, 1, 0, 2));

	ttFire = maxFire;
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
	if (ttHit > 0)
		ttHit--;
}

void Player::onLevel()
{
	if (score >= toLvl)
	{
		if (lvl & 1)
			hp++;
		if (lvl % 4 == 0 && ttFire > 3)
			ttFire--;

		lvl++;
		toLvl += lvl * 10000;
	}
}

void Player::drawStats(World &world)
{
	uint32_t ws = (world.ttWave * (1000000 / TPS)) / 1000000;
	uint32_t ms = (tick * (1000000 / TPS)) / 1000;

	werase(world.hud);
	mvwprintw(world.hud, 0, 0, "%.2u:%.2u.%.3u -- %.10u -- Wave %u; next in T-%.2u:%.2u",
		ms / 1000 / 60, ms / 1000 % 60, ms % 1000,
		score,
		world.wave,
		ws / 60, ws % 60
	);
	wrefresh(world.hud);
}

void Player::onDraw(World &world)
{
	wattron(world.window, COLOR_PAIR(2));

	for (uint16_t x = this->x; x < world.w; x++)
		mvwaddch(world.window, y, x, '-');

	mvwprintw(world.window, y, x - 3, "L%u", lvl);
	mvwprintw(world.window, y + 1, x, "%u", hp);

	int fx = (ttHit > 0) ? (COLOR_PAIR(2)) : (COLOR_PAIR(1));

	mvwaddch(world.window, y, x, '>' | fx);

	wattroff(world.window, COLOR_PAIR(2));
}

bool Player::onHit(World &, Entity &)
{
	if (ttHit > 0)
		return false;
	ttHit = 15;
	return (--hp <= 0);
}
