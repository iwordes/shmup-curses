/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:47:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 20:34:21 by iwordes          ###   ########.fr       */
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

private:

	WINDOW *term;
	WINDOW *winGame;
	// WINDOW *winHud;

	Player *player;

	Entity **bg;
	Entity **fg;
	uint32_t fgLen;
	uint32_t bgLen;

	// uint32_t clock;

	// uint32_t maxTtCycle;
	// uint32_t ttCycle;

	uint32_t maxTtSpawn;
	uint32_t minTtSpawn;
	uint32_t ttSpawn;

	// =================================================================================================================

public:
	void start();

	void addBg(Entity *entity);
	void addFg(Entity *entity);

private:
	void tick();
	void pause();
	void spawn();

	void draw();
	void drawClip(const Entity &entity);

	bool bound(Entity &entity);
	bool collide(Entity &entity);
};

#endif
