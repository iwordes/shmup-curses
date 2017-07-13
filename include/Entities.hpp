/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entities.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:35:23 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 15:17:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_HPP
# define ENTITIES_HPP
# include <stdint.h>

class Entity;
class World;

class Entities
{
public:
	Entities();
	~Entities();

public:
	void add(Entity *entity);
	void tick(World &world);
	void draw(World &world);

	bool collide(World &world, Entity &with);

	void addCollider(Entities &add);
	void setEffect(int effect);
	void clear(uint32_t i = 0);

	Entity *operator[](uint32_t i) const;

private:
	bool _doCull(World &w, Entity &entity);
	bool _doCollide(World &w, uint32_t i);

	int effect;

	Entity **arr;
	uint32_t len;

	Entities **collider;
	uint16_t col_len;
};

#endif
