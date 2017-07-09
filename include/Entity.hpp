/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:36:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 01:55:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <stdint.h>

class World;

class Entity
{
public:
	Entity(const char *icon = "?", int16_t x = 0, int16_t y = 0, uint16_t w = 1, uint16_t h = 1);
	Entity(const Entity &copy);
	virtual ~Entity();

	const Entity &operator=(const Entity &rhs);


	const char *icon;
	uint16_t w;
	uint16_t h;

	int16_t x;
	int16_t y;

	uint8_t type;


	virtual void onTick(World &world);
	virtual bool onHit(World &world, Entity &by);
};

#endif
