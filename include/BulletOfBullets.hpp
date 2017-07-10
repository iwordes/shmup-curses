/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletOfBullets.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:54:08 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 22:09:45 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOB_HPP
# define BOB_HPP

# include "Projectile.hpp"
# include "World.hpp"

class BulletOfBullets: virtual public Projectile
{
public:
	BulletOfBullets(uint8_t type = -1, const char *icon = "=",
		int16_t x = 0, int16_t y = 0, int16_t tx = -1, int16_t ty = 0, uint8_t ttSplit = 20);
	BulletOfBullets(const BulletOfBullets &);
	~BulletOfBullets();

	BulletOfBullets &operator=(const BulletOfBullets &);

	uint8_t maxTtSplit;
	uint8_t ttSplit;

	virtual void onTick(World &world);
	virtual void onSplit(World &world);
};

#endif
