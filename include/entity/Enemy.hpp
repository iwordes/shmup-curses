/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:07:22 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:22:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "Entity.hpp"

class Enemy: public Entity
{
public:
	Enemy(const char *icon, int16_t x, int16_t y, uint16_t w, uint16_t h);

	uint8_t maxFire;
	uint8_t ttFire;

	virtual void onTick(World &world);
	virtual void onFire(World &world) = 0;

protected:
	int8_t moveX;
	int8_t moveY;
	int8_t ttx;
	int8_t tty;
};

#endif
