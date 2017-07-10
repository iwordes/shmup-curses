/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shooter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:37:03 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 17:43:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyShooter.hpp>

EnemyShooter::EnemyShooter(int16_t x, int16_t y): Enemy("<", x, y, 1, 1) {}
EnemyShooter::EnemyShooter(const EnemyShooter &copy) { *this = copy; }
EnemyShooter::~EnemyShooter() {}

EnemyShooter &EnemyShooter::operator=(const EnemyShooter &rhs)
{
	Enemy::operator=(rhs);
	return *this;
}

// =====================================================================================================================

void EnemyShooter::onFire(World &world)
{
	world.addFg(new Projectile(type, "c", x - 1, y));
}
