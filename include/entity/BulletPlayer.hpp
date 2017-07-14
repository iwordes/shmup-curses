/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletPlayer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:30:54 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 16:40:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETPLAYER_HPP
# define BULLETPLAYER_HPP
# include "Bullet.hpp"
# include "World.hpp"

class BulletPlayer: public Bullet
{
public:
	BulletPlayer(const char *icon, int16_t x, int16_t y, int16_t ttx, int16_t tty, uint8_t hp = 0);

	uint8_t hp;

	virtual bool onHit(World &world, Entity &by);
};

#endif
