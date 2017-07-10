/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:11:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 19:35:41 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <World.hpp>
#include <Enemy.hpp>

#include <EnemyShooter.hpp>
#include <EnemyKamikaze.hpp>

#include <EnemyBomber.hpp>

#include <EnemyOcto.hpp>

#include <EnemyGatling.hpp>

static std::random_device rd;
static std::mt19937 rng(rd());

static bool chance(int n, int max)
{
	return (rng() % max < (unsigned)n);
}

#define ADD(T) addFg(new T(w - 1, rng() % h))

void World::spawn()
{
	if (wave >= 20 && chance(1, 10))
		;// ...
	else if (wave >= 20 && chance(1, 10))
		;// ...
	else if (wave >= 15 && chance(1, 8))
		;// ...
	else if (wave >= 15 && chance(1, 30))
		ADD(EnemyGatling);
	else if (wave >= 10 && chance(1, 8))
		ADD(EnemyOcto);
	else if (wave >= 10 && chance(1, 5))
		;// ...
	else if (wave >= 5 && chance(1, 3))
		;// ...
	else if (wave >= 5 && chance(1, 3))
		ADD(EnemyBomber);
	else if (chance(1, 3))
		ADD(EnemyShooter);
	else
		ADD(EnemyKamikaze);
}
