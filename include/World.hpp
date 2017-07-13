/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:43:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 14:18:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

# define TPS 30

class World
{
public:
	World();
	~World();

public:
	start();

private:
	tick();
	draw();
	spawn();

public:
	Entities bg;
	Entities fg1;
	Entities fg2;

	WINDOW *term;
	WINDOW *window;
	WINDOW *hud;

	int32_t w;
	int32_t h;

	uint32_t ttSpawn;
	uint32_t ttWave;
	uint32_t wave;
};

#endif
