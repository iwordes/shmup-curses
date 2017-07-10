/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShooter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:20:21 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 17:42:19 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYSHOOTER_HPP
# define ENEMYSHOOTER_HPP
# include "Enemy.hpp"

class EnemyShooter: public Enemy
{
public:
	EnemyShooter(int16_t x = 0, int16_t y = 0);
	EnemyShooter(const EnemyShooter &copy);
	~EnemyShooter();

	EnemyShooter &operator=(const EnemyShooter &rhs);

	void onFire(World &world);
};

#endif
