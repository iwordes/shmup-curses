/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyRunner.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:17:09 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 18:22:30 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYRUNNER_HPP
# define ENEMYRUNNER_HPP
# include "Enemy.hpp"

class EnemyRunner: public Enemy
{
public:
	EnemyRunner(int16_t x, int16_t y);

	void onFire(World &);
};

#endif
