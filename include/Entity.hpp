/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:36:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 22:05:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

# include <stdint.h>

class World;

class Entity
{
public:
	Entity();
	Entity(const Entity &copy);
	virtual ~Entity();

	const Entity &operator=(const Entity &rhs);


	const char *icon;
	uint16_t w;
	uint16_t h;

	int16_t x;
	int16_t y;

	// uint8_t type;

	bool isSolid;
	bool isHostile;


	virtual void onTick(World &world);

	// Return false to cancel death, e.g. if hitpoints are left.
	// virtual bool onHit(World &world, Entity &by);
};

#endif
