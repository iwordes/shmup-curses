/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World::spawn.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:13:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:21:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <World.hpp>
#include <EnemyRunner.hpp>

static std::random_device rd;
static std::mt19937 rng(rd());

#define ADD(T) fg2.add(new T(w - 1, rng() % h))

void World::spawn()
{
	if (ttWave-- <= 0)
	{
		ttWave = wave * 20 * TPS;
		wave++;
	}

	if (ttSpawn-- <= 0)
	{
		ttSpawn = std::max(90 - (int)(wave * 5), 30);
		ADD(EnemyRunner);
	}
}
