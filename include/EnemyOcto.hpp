/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyOcto.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:48:59 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 12:16:28 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYOCTO_HPP
# define ENEMYOCTO_HPP

# include "Enemy.hpp"
# include "World.hpp"

class EnemyOcto: public Enemy
{
public:
	EnemyOcto(int16_t x = 0, int16_t y = 0);
	EnemyOcto(const EnemyOcto &copy);
	~EnemyOcto();

	EnemyOcto &operator=(const EnemyOcto &rhs);

	uint8_t ff;

	virtual void onFire(World &world);
};

#endif
