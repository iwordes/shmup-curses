/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyTwirly.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:06:30 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 21:13:43 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYTWIRLY_HPP
# define ENEMYTWIRLY_HPP

# include "Enemy.hpp"

class EnemyTwirly: public Enemy
{
public:
	EnemyTwirly(int16_t x = 0, int16_t y = 0);
	EnemyTwirly(const EnemyTwirly &);
	~EnemyTwirly();

	EnemyTwirly &operator=(const EnemyTwirly &);

	uint8_t side;

	void onFire(World &world);
};

#endif
