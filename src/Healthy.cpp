/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Health.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:42:44 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 20:45:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Healthy.hpp>

void Healthy::onTick(World &)
{
	if (ttHit > 0)
		ttHit--;
}

void Healthy::onHit(World &, Entity &)
{
	if (ttHit > 0)
		return false;
	ttHit = maxTtHit;
	return (hp-- <= 0);
}

// =====================================================================================================================

Healthy::Healthy() {}
Healthy::Healthy(const Healthy &) {}
Healthy::~Healthy() {}

Healthy &Healthy::operator=(const Healthy &) { return *this; }
