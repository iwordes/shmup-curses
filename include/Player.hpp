/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:40:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 22:58:32 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <stdint.h>
# include "Entity.hpp"
# include "Projectile.hpp"
# include "World.hpp"

class Player: public Entity
{
public:
	Player(uint16_t x = 0, uint16_t y = 0);
	Player(const Player &copy);
	~Player();

	const Player &operator=(const Player &rhs);

	uint8_t ttFire;
	uint8_t maxTtFire;

	uint8_t ttMove;
	uint8_t maxTtMove;

	int8_t hp;

	uint32_t score;
	uint32_t time;

	void onTick(World &world);
	void onMove(World &world);
	void onFire(World &world);
};

#endif
