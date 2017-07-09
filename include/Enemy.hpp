/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:40:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 14:04:25 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <random>
# include "Entity.hpp"
# include "Projectile.hpp"
# include "World.hpp"

class Enemy: public Entity
{
public:
	Enemy(const char *icon = "<", int16_t x = 0, int16_t y = 0, uint16_t w = 1, uint16_t h = 1);
	Enemy(const Enemy &copy);
	~Enemy();

	const Enemy &operator=(const Enemy &rhs);

	uint16_t ttFire;
	uint16_t maxTtFire;

	uint16_t ttMove;
	uint16_t maxTtMove;

	uint16_t score;

	bool isEnemy();

	virtual void onTick(World &world);
	virtual void onFire(World &world);
};

#endif
