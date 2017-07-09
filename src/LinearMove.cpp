/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearMove.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:07:26 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 16:09:42 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <LinearMove.hpp>

void LinearMove::onTick(World &)
{
	int8_t dx = 0;
	int8_t dy = 0;

	if (maxTtx != 0)
		dx = (maxTtx > 0) ? 1 : -1;
	if (maxTty != 0)
		dy = (maxTty > 0) ? 1 : -1;

	if (ttx == 0)
	{
		ttx = maxTtx;
		x += dx;
	}
	if (tty == 0)
	{
		tty = maxTty;
		y += dy;
	}

	ttx -= dx;
	tty -= dy;
}

// =====================================================================================================================

LinearMove::LinearMove() {}
LinearMove::LinearMove(const LinearMove &) {}
LinearMove::~LinearMove() {}

LinearMove &LinearMove::operator=(const LinearMove &) { return *this; }
