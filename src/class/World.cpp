/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:31:13 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 13:15:33 by iwordes          ###   ########.fr       */
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

	this->maxTtWave = 120;
	this->minTtWave = 12;
	this->ttWave = 60;
	this->wave = 0;

	// -----------------------------------

	term = initscr();
	curs_set(false);
	noecho();
	timeout(0);

	winGame = subwin(term, h, w, 0, 0);
	winHud = subwin(term, 1, w, h, 0);
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
	delwin(winHud);
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

	fg[0] = new Player(0, h / 2);
	while (fg[0] != NULL)
	{
		t1 = utime();
		tick();
		t2 = utime();
		if (t2 - t1 < 50000)
			usleep(50000 - (t2 - t1));
	}

	werase(winHud);
	mvwprintw(winHud, 0, w / 2 - 7, ":: You lose! ::");
	wrefresh(winHud);
	pause();
}

// =====================================================================================================================

static inline bool onTick(World &w, Entity **&ent, uint64_t i)
{
	if (ent[i] == NULL)
		return (false);
	if (!w.bound(*ent[i]))
	{
		delete ent[i];
		ent[i] = NULL;
	}
	return (ent[i] != NULL);
}

void World::tick()
{
	for (uint64_t i = 0; i < bgLen; i++)
		if (onTick(*this, bg, i))
			bg[i]->onTick(*this);

	for (uint64_t i = 0; i < fgLen; i++)
		if (onTick(*this, fg, i) && !collide(*fg[i]))
			fg[i]->onTick(*this);

	if (ttWave <= 0)
	{
		ttWave = maxTtWave;
		if (maxTtWave > minTtWave)
			maxTtWave -= 3;
		wave += 1;
		spawn();
	}
	ttWave--;

	draw();
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
	for (uint16_t y = 0; y < e.h; y++) if (e.y + y >= 0 && e.y + y < (int)h)
		for (uint16_t x = 0; x < e.w; x++) if (e.x + x >= 0 && e.x + x < (int)w)
			if (e.icon[y * e.w + x] != ' ')
				mvwaddch(winGame, e.y + y, e.x + x, e.icon[y * e.w + x]);
}

void World::draw()
{
	werase(winGame);
	for (uint32_t i = 0; i < bgLen; i++)
		if (bg[i] != NULL)
			drawClip(*bg[i]);
	for (uint32_t i = 0; i < fgLen; i++)
		if (fg[i] != NULL)
			drawClip(*fg[i]);
	wrefresh(winGame);
}

// =====================================================================================================================

bool World::bound(Entity &e)
{
	return (
		e.x < (int)w && // Lent < Rwin &&
		e.x + e.w > 0   // Rent > Lwin
	) &&
	(
		e.y < (int)h && // Tent < Bwin &&
		e.y + e.h > 0   // Bent > Twin
	);
}

static inline bool doesCollide(const Entity &e1, const Entity &e2)
{
	return (
		(
			e1.type != e2.type
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
	for (uint32_t i = 0; i < fgLen; i++)
		if (fg[i] != NULL)
			if (doesCollide(e, *fg[i]))
			{
				uint32_t f = 0;

				for (; f < fgLen; f++)
					if (fg[f] == &e)
						break;

				bool del1 = fg[f]->onHit(*this, *fg[i]);
				bool del2 = fg[i]->onHit(*this, *fg[f]);

				if (del1)
				{
					delete fg[f];
					fg[f] = NULL;
				}
				if (del2)
				{
					delete fg[i];
					fg[i] = NULL;
				}

				return (del1);
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
	for (uint32_t i = l; i < l * 2; i++)
		tmp[i] = NULL;
	tmp[l] = ent;

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
