/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyGatling.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:23:14 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 18:30:29 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYGATLING_HPP
# define ENEMYGATLING_HPP

# include "Enemy.hpp"

class EnemyGatling: public Enemy
{
public:
	EnemyGatling(int16_t x, int16_t y);
	EnemyGatling(const EnemyGatling &copy);
	~EnemyGatling();

	EnemyGatling &operator=(const EnemyGatling &rhs);

	// =================================================================================================================

	int8_t tt;

	virtual void onTick(World &world);
	virtual void onFire(World &world);
	virtual void onMove(World &world);
};

#endif
