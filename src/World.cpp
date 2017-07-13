/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:42:44 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 15:15:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <World.hpp>
#include "Entities.hpp"
#include "Player.hpp"

World::World()
{
	this->w = COLS;
	this->h = LINES - 2;

	this->ttSpawn = 90;
	this->ttWave = 90;
	this->wave = 0;

	// --------------------

	this->term = initscr();
	this->window = subwin(term, h, w, 0, 0);
	this->hud = subwin(term, 2, w, h, 0);

	curs_set(false);
	noecho();
	timeout(0);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, 52, COLOR_BLACK);
	init_pair(3, 33, COLOR_BLACK);
}

World::~World()
{
	endwin();
	delwin(hud);
	delwin(window);
	delscreen((SCREEN*)term);
}

// =====================================================================================================================

static uint64_t utime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void World::start()
{
	uint64_t t1;
	uint64_t t2;

	fg1.add(new Player(1, h / 2));
	while (fg1[0] != NULL)
	{
		t1 = utime();
		spawn();
		tick();
		draw();
		t2 = utime();

		if (t2 - t1 < 33333)
			usleep(33333 - (t2 - t1));
	}
}

// =====================================================================================================================

void World::tick()
{
	bg.tick(*this);
	fg1.tick(*this);
	fg2.tick(*this);
}

void World::draw()
{
	werase(window);
	bg.draw(*this);
	fg1.draw(*this);
	fg2.draw(*this);
	wrefresh(window);
}
