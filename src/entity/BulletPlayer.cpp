/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletPlayer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:33:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 16:40:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BulletPlayer.hpp>

BulletPlayer::BulletPlayer(const char *icon, int16_t x, int16_t y, int16_t ttx, int16_t tty, uint8_t hp): Bullet(icon, x, y, ttx, tty)
{
	this->hp = hp;
}

bool BulletPlayer::onHit(World &world, Entity &by)
{
	world.fg1[0]->score += by.score;
	return (hp-- > 0);
}
