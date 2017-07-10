/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerBOB.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 22:02:03 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 22:49:36 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYERBOB_HPP
# define PLAYERBOB_HPP

# include "PlayerBullet.hpp"
# include "BulletOfBullets.hpp"

class PlayerBOB: public PlayerBullet, public BulletOfBullets
{
public:
	PlayerBOB(int16_t x = 0, int16_t y = 0);
	PlayerBOB(const PlayerBOB &);
	~PlayerBOB();

	PlayerBOB &operator=(const PlayerBOB &);

	uint8_t hp;

	using BulletOfBullets::onTick;
	using BulletOfBullets::onSplit;

	bool onHit(World &world, Entity &by);
};

#endif
