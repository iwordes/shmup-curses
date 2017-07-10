/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:03:11 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 18:15:14 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYBAT_HPP
# define ENEMYBAT_HPP

# include "Enemy.hpp"
# include "World.hpp"

class EnemyBat: public Enemy
{
private:
	int down;

public:
	EnemyBat(int16_t x = 0, int16_t y = 0);
	EnemyBat(const EnemyBat &copy);
	~EnemyBat();

	EnemyBat &operator=(const EnemyBat &rhs);

	Projectile payload;

	virtual void onTick(World &world);

};

#endif
