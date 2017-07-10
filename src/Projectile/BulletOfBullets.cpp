/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletOfBullets.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:36:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 22:16:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BulletOfBullets.hpp>

BulletOfBullets::BulletOfBullets(uint8_t type, const char *icon, int16_t x, int16_t y, int16_t tx, int16_t ty, uint8_t ttSplit)
	: Projectile(type, icon, x, y, tx, ty)
{
	this->maxTtSplit = ttSplit;
	this->ttSplit = ttSplit;
}

BulletOfBullets::BulletOfBullets(const BulletOfBullets &) {}
BulletOfBullets::~BulletOfBullets() {}

BulletOfBullets &BulletOfBullets::operator=(const BulletOfBullets &)
{
	return *this;
}

// =====================================================================================================================

void BulletOfBullets::onTick(World &world)
{
	if (ttSplit == 0)
	{
		onSplit(world);
		ttSplit = maxTtSplit;
	}
	ttSplit--;

	Projectile::onTick(world);
}

void BulletOfBullets::onSplit(World &world)
{
	int tx = (ttx < 0) ? -2 : 2;

	world.addFg(new Projectile(type, "\\", x, y, tx, -2));
	world.addFg(new Projectile(type, "/",  x, y, tx, 2));
}
