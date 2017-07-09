/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:40:58 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/08 19:18:03 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy: Entity
{
	Enemy(char *icon = "<", uint16_t w = 1, uint16_t h = 1, uint16_t);
	~Enemy();

	uint16_t ttf;
	uint16_t maxTtf;

	uint16_t ttMove;
	uint16_t maxTtMove;

	uint16_t score;

	virtual void onTick(World &world);
};

#endif
