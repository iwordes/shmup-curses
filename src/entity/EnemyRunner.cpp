/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyRunner.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:18:20 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:22:39 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyRunner.hpp>

EnemyRunner::EnemyRunner(int16_t x, int16_t y): Enemy("<<", x, y, 2, 1)
{
	this->moveX = -3;
}

void EnemyRunner::onFire(World &) {}
