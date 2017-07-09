/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:17:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 20:23:20 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Entity.hpp>
#include <World.hpp>

Entity::Entity() {}

Entity::Entity(const Entity &)
{
	throw "Don't do that.";
}

Entity::~Entity() {}

const Entity &Entity::operator=(const Entity &)
{
	throw "Don't do that.";
}

// =====================================================================================================================

// virtual bool Entity::onHit(World &world, Entity &by) { return true; }
