/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sawtooth.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:28:26 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 22:35:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAWTOOTH_HPP
# define SAWTOOTH_HPP

# include "Projectile.hpp"

class Sawtooth: public Projectile
{
public:
	Sawtooth(uint8_t type = -1, const char *icon = "x", int16_t x = 0, int16_t y = 0, int8_t d = 1);
	Sawtooth(const Sawtooth &);
	~Sawtooth();

	Sawtooth &operator=(const Sawtooth &);

	int8_t d;
	int8_t ttTurn;

	void onTick(World &);
	bool onHit(World &world, Entity &by);
};

#endif
