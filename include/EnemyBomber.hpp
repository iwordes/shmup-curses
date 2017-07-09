/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBomber.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:24:43 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 12:07:57 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYBOMBER_HPP
# define ENEMYBOMBER_HPP

# include "Enemy.hpp"
# include "World.hpp"

class EnemyBomber: public Enemy
{
public:
	EnemyBomber(int16_t x = 0, int16_t y = 0);
	EnemyBomber(const EnemyBomber &copy);
	~EnemyBomber();

	EnemyBomber &operator=(const EnemyBomber &rhs);

	Projectile payload;

	virtual void onFire(World &world);
};

#endif
