/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerBullet.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:44:03 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 14:31:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Enemy.hpp>
#include <PlayerBullet.hpp>

PlayerBullet::PlayerBullet(const char *icon, int16_t x, int16_t y, uint8_t tx, uint8_t ty): Projectile(0, icon, x, y, tx, ty) {}
PlayerBullet::PlayerBullet(const PlayerBullet &copy) { *this = copy; }
PlayerBullet::PlayerBullet(const Projectile &copy) { *this = copy; }
PlayerBullet::~PlayerBullet() {}

PlayerBullet &PlayerBullet::operator=(const PlayerBullet &rhs)
{
	Projectile::operator=(rhs);
	return (*this);
}

PlayerBullet &PlayerBullet::operator=(const Projectile &rhs)
{
	Projectile::operator=(rhs);
	return (*this);
}

// =====================================================================================================================

bool PlayerBullet::onHit(World &world, Entity &by)
{
	if (by.isEnemy())
		world.fg[0]->score += ((Enemy*)&by)->score;
	else if (by.isBullet())
		world.fg[0]->score += 100;
	return (true);
}
