/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:01:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 18:26:01 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <World.hpp>
#include <Scenery.hpp>

void World::scene()
{
	int n = rng() % 4;
	Entity *tmp;

	//if (n == 0)
	//	tmp = new SceneryAsteroid1()

	// ...

	if (rng() & 8)
		addFg(tmp);
	else
		addBg(tmp);
}
