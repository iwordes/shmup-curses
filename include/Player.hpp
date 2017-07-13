/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:28:46 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 14:48:21 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player: public Entity, public Healthy
{
public:
	Player(int16_t x, int16_t y);

	uint8_t maxFire;
	uint8_t maxMove;

	uint8_t ttFire;
	uint8_t ttMove;
	uint8_t ttHit;

	uint32_t toLvl;
	uint8_t  lvl;

	void onTick(World &world);

	void onMove(World &world);
	void onFire(World &world);
	void onLevel();

	void drawStats(World &world);
};

#endif
