/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:37:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 02:03:40 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

# include <stdint.h>
# include "Entity.hpp"

class Projectile: public Entity
{
public:
	Projectile(uint8_t type = -1, const char *icon = "c", int16_t x = 0, int16_t y = 0, int8_t tx = -3, int8_t ty = 0);
	Projectile(const Projectile &copy);
	virtual ~Projectile();

	const Projectile &operator=(const Projectile &rhs);

	int8_t mttx;
	int8_t mtty;
	int8_t ttx;
	int8_t tty;

	virtual void onTick(World &world);
};

#endif
