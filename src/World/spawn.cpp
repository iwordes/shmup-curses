/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:11:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 12:11:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <World.hpp>
#include <Enemy.hpp>
#include <EnemyBomber.hpp>
#include <EnemyOcto.hpp>

static std::random_device rd;
static std::mt19937 rng(rd());

void World::spawn()
{
	switch (rng() % 3)
	{
		case 0: addFg(new Enemy("<", w - 1, rng() % h)); break;
		case 1: addFg(new EnemyBomber(w - 1, rng() % h)); break;
		case 2: addFg(new EnemyOcto(w - 1, rng() % h)); break;
	}
}
