/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 12:17:27 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 19:56:16 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Entity.hpp>

virtual Entity::Entity() {}
virtual Entity::~Entity() {}

virtual Entity::Entity(const Entity &)
{
	throw "Don't do that.";
}

virtual const Entity &Entity::operator=(const Entity &)
{
	throw "Don't do that.";
}

// =====================================================================================================================

// virtual bool Entity::onHit(World &world, Entity &by) { return true; }
