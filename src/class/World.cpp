/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:31:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 20:49:15 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <World.hpp>
#include <Player.hpp>

World::World(uint32_t w, uint32_t h)
{
	this->w = w;
	this->h = h;

	this->bg = new Entity*[8];
	this->fg = new Entity*[8];
	this->bgLen = 8;
	this->fgLen = 8;

	for (uint32_t i = 0; i < 8; i++)
	{
		bg[i] = NULL;
		fg[i] = NULL;
	}

	// this->clock = 0;

	this->maxTtSpawn = 60;
	this->minTtSpawn = 6;
	this->ttSpawn = maxTtSpawn;

	// -----------------------------------

	term = initscr();
	curs_set(false);
	noecho();
	timeout(0);

	winGame = newwin(24, 80, 0, 0);
	// winHud = newwin(2, 80, 81, 81);
}

World::~World()
{
	for (uint32_t i = 0; i < fgLen; i++)
		delete fg[i];
	for (uint32_t i = 0; i < bgLen; i++)
		delete bg[i];
	delete fg;
	delete bg;

	endwin();
	delwin(winGame);
	// delscreen(term);
}

World::World(const World &)
{
	throw "Don't create more than one world.";
}

const World &World::operator=(const World &)
{
	throw "Don't create more than one world.";
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

	player = new Player(0, 0);
	fg[0] = player;

	while (fg[0] != NULL)
	{
		t1 = utime();
		tick();
		t2 = utime();
		if (t2 - t1 < 50000)
			usleep(50000 - (t2 - t1));
	}

	// Game over ...
}

// =====================================================================================================================

void World::tick()
{
	for (uint64_t i = 0; i < bgLen; i++)
		if (bg[i] != NULL && bound(*bg[i]))
			bg[i]->onTick(*this);

	for (uint64_t i = 0; i < fgLen; i++)
		if (fg[i] != NULL && bound(*fg[i]) && (!collide(*fg[i])/* || fg[i]->isImmortal */))
			fg[i]->onTick(*this);

	if (ttSpawn <= 0)
	{
		ttSpawn = maxTtSpawn;
		if (maxTtSpawn > minTtSpawn)
			maxTtSpawn -= 3;
		spawn();
	}

	// --------------------------------------------

	player->time += 50;
	player->score += 5;

	draw();
}

void World::spawn()
{
	// TODO
	// ...
}

void World::pause()
{
	timeout(-1);
	while (getch() != 'p');
	timeout(0);
}

// =====================================================================================================================

void World::drawClip(const Entity &e)
{
	for (uint16_t y = 0; y < e.h; y++) if (e.y + y > 0 && e.y + y < (int)h)
		for (uint16_t x = 0; x < e.w; x++) if (e.x + x > 0 && e.x + x < (int)w)
			if (e.icon[y * e.w + x] != ' ')
				mvwaddch(winGame, e.y + y, e.x + x, e.icon[y * e.w + x]);
}

void World::draw()
{
	werase(winGame);
	for (uint32_t i = 0; i < bgLen; i++)
		drawClip(*bg[i]);
	for (uint32_t i = 0; i < fgLen; i++)
		drawClip(*fg[i]);
	wrefresh(winGame);
}

// =====================================================================================================================

bool World::bound(Entity &e)
{
	return (
		(
			e.x < (int)w &&    // Lent < Rwin &&
			e.x + e.w > 0 // Rent > Lwin
		) &&
		(
			e.y < (int)h &&    // Tent < Bwin &&
			e.y + e.h > 0 // Bent > Twin
		)
	);
}

static inline bool doesCollide(const Entity &e1, const Entity &e2)
{
	return (
		(
			e1.isSolid && e2.isSolid &&
			e1.isHostile != e2.isHostile
		) &&
		(
			e1.x < e2.x + e2.w && // Le1 < Re2 &&
			e1.x + e1.w > e2.x    // Re1 > Le2
		) &&
		(
			e1.y < e2.y + e2.h && // Te1 < Be2 &&
			e1.y + e1.h > e2.y    // Be1 > Te2
		)
	);
}

bool World::collide(Entity &e)
{
	if (!e.isSolid)
		return (false);
	for (uint32_t i = 0; i < fgLen; i++)
		if (doesCollide(e, *fg[i]))
		{
			// Find Entity e as fg[f]...

			// delete fg[f];
			// delete fg[i];
			// fg[f] = NULL;
			// fg[i] = NULL;
			return (true);
		}
	return (false);
}

// =====================================================================================================================

static inline void addEntity(Entity **&arr, uint32_t &l, Entity *ent)
{
	for (uint32_t i = 0; i < l; i++)
		if (arr[i] == NULL)
		{
			arr[i] = ent;
			return;
		}

	Entity **tmp = new Entity*[l * 2];

	for (uint32_t i = 0; i < l; i++)
		tmp[i] = arr[i];
	for (uint32_t i = 0; i < l * 2; i++)
		tmp[i] = NULL;
	arr[l] = ent;

	delete arr;
	arr = tmp;
	l *= 2;
}

void World::addBg(Entity *ent)
{
	addEntity(bg, bgLen, ent);
}

void World::addFg(Entity *ent)
{
	addEntity(fg, fgLen, ent);
}
