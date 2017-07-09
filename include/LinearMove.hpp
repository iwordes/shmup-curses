/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearMove.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 16:01:00 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 16:17:13 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEARMOVE_HPP
# define LINEARMOVE_HPP

# include "World.hpp"

class LinearMove
{
	int16_t x;
	int16_t y;

	int8_t maxTtx;
	int8_t maxTty;
	int8_t ttx;
	int8_t tty;

	virtual void onTick(World &world);

	// =================================================================================================================

	LinearMove();
	LinearMove(const LinearMove &);
	virtual ~LinearMove() = 0;
	LinearMove &operator=(const LinearMove &);
};

#endif
