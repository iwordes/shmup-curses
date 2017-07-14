/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBomber.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:03:03 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 20:08:18 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYBOMBER_HPP
# define ENEMYBOMBER_HPP
# include "Bullet.hpp"
# include "Enemy.hpp"
# include "World.hpp"

class EnemyBomber: public Enemy
{
public:
	EnemyBomber(int16_t x, int16_t y);

	void onFire(World &world);
};

#endif
