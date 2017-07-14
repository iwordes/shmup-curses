/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:33:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 20:42:46 by iwordes          ###   ########.fr       */
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
	if (ttHit > 0)
		ttHit--;
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
