/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:42:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 18:17:57 by iwordes          ###   ########.fr       */
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
}

Player::~Player()
{
	// ...
}


void	Player::onTick(World &world)
{
	int c;

	if ((c = getch()) != ERR)
	{
		if ((c == 'w' || c == 'a' || c == 's' || c == 'd') && ttMove == 0)
		{
			ttMove = maxTtMove;
			if (c == 'w' && y > 0)
				y -= 1;
			else if (c == 'a' && x > 0)
				x -= 1;
			else if (c == 's' && y < world.h - 1)
				y += 1;
			else if (c == 'd' && y < world.w - 1)
				x += 1;
			else
				ttMove = 0;
		}
	}
	while (getch() != ERR);

	if (ttFire == 0)
	{
		this->onFire();
		ttFire = maxTtFire;
	}

	ttMove--;
	ttFire--;
}

void Player::onFire(World &world)
{
	/*world.addEntity(new Projectile(
		// ...
	));*/
}
