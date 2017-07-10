/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kamikaze.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:50:19 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 18:34:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyKamikaze.hpp>

EnemyKamikaze::EnemyKamikaze(int16_t x, int16_t y): Enemy("<<", x, y, 2)
{
	this->maxTtFire = 1024;
	this->maxTtMove = 3;
	this->ttMove = 5;
	this->score = 100;
}

EnemyKamikaze::EnemyKamikaze(const EnemyKamikaze &copy)
{
	*this = copy;
}

EnemyKamikaze::~EnemyKamikaze() {}

EnemyKamikaze &EnemyKamikaze::operator=(const EnemyKamikaze &rhs)
{
	Enemy::operator=(rhs);
	return (*this);
}

void EnemyKamikaze::onFire(World &) {}
