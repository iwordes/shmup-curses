/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:36:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 14:04:12 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <stdint.h>

class World;

class Entity
{
public:
	Entity(const char *icon, int16_t x, int16_t y, uint16_t w = 1, uint16_t h = 1);

	const char *icon;
	uint16_t w;
	uint16_t h;
	int16_t x;
	int16_t y;

	uint32_t score;
	uint8_t  type;

	virtual void onTick(World &world);
	virtual bool onHit(World &world, Entity &by);
};

#endif
