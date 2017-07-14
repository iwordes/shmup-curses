/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:19:30 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:23:04 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP
# include "Entity.hpp"
# include "World.hpp"

class Bullet: public Entity
{
public:
	Bullet(const char *icon, int16_t x, int16_t y, int16_t ttx, int16_t tty);

	virtual void onTick(World &);

protected:
	int8_t moveX;
	int8_t moveY;
	int8_t ttx;
	int8_t tty;
};

#endif
