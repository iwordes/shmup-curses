/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemySpiky.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:26:35 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 21:35:00 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYSPIKY_HPP
# define ENEMYSPIKY_HPP

# include "Enemy.hpp"

class EnemySpiky: public Enemy
{
public:
	EnemySpiky(int16_t x = 0, int16_t y = 0);
	EnemySpiky(const EnemySpiky &);
	~EnemySpiky();

	EnemySpiky &operator=(const EnemySpiky &);

	bool ff;

	void onFire(World &world);
};

#endif
