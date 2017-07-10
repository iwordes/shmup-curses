/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:47:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 16:59:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

# include <curses.h>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>
# include "Entity.hpp"

class Player;

class World
{
public:
	World(uint32_t x = 80, uint32_t y = 24);
	World(const World &copy);
	~World();

	const World &operator=(const World &rhs);

	// =================================================================================================================

	uint32_t w;
	uint32_t h;

	WINDOW *term;
	WINDOW *winGame;
	WINDOW *winHud;

	uint32_t maxTtSpawn;
	uint32_t minTtSpawn;
	uint32_t ttSpawn;
	uint32_t ttScene;

	uint32_t ttWave;
	uint32_t wave;

	Entity **bg;
	Entity **fg;
	uint32_t fgLen;
	uint32_t bgLen;

	// =================================================================================================================

public:
	void start();

	void addBg(Entity *entity);
	void addFg(Entity *entity);

	bool bound(Entity &entity);
	bool collide(Entity &entity);

private:
	void tick();
	void pause();
	void spawn();

	void draw();
	void drawClip(const Entity &entity);
};

#endif
