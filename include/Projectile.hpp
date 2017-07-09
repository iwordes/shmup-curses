/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:37:31 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 19:53:48 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

class Projectile: Entity
{
public:
	Projectile(const char *icon = "-", int16_t x = 0, int16_t y = 0, int8_t tx = -10, int8_t ty = 0);
	Projectile(const Projectile &copy);
	virtual ~Projectile();

	const Projectile &operator=(const Projectile &rhs);

	int8_t mttx;
	int8_t mtty;
	int8_t ttx;
	int8_t tty;

	virtual void onTick(World &world);
	// virtual void onHit(World &world, Entity &by);
};

#endif
