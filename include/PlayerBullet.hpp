/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerBullet.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:14:56 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 14:30:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERBULLET_HPP
# define PLAYERBULLET_HPP

# include "Projectile.hpp"
# include "World.hpp"

class PlayerBullet: public Projectile
{
public:
	PlayerBullet(const char *icon = "=", int16_t x = 0, int16_t y = 0, uint8_t tx = 1, uint8_t ty = 0);
	PlayerBullet(const PlayerBullet &copy);
	PlayerBullet(const Projectile &copy);
	~PlayerBullet();

	PlayerBullet &operator=(const PlayerBullet &rhs);
	PlayerBullet &operator=(const Projectile &rhs);

	bool onHit(World &world, Entity &by);
};

#endif
