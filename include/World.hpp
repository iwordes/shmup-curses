/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:47:39 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 02:09:31 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_HPP
# define WORLD_HPP

# include <curses.h>
# include <random>
# include <stdint.h>
# include <sys/time.h>
# include <unistd.h>
# include "Entity.hpp"
# include "Enemy.hpp"

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

	uint32_t ttWave;
	uint32_t wave;

private:

	Entity **bg;
	Entity **fg;
	uint32_t fgLen;
	uint32_t bgLen;

	uint32_t maxTtWave;
	uint32_t minTtWave;

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
