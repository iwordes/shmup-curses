/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyKamikaze.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 17:01:40 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 17:22:15 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYKAMIKAZE_HPP
# define ENEMYKAMIKAZE_HPP

# include "Enemy.hpp"
# include "World.hpp"

class EnemyKamikaze: public Enemy
{
public:
	EnemyKamikaze(int16_t x = 0, int16_t y = 0);
	EnemyKamikaze(const EnemyKamikaze &copy);
	~EnemyKamikaze();

	EnemyKamikaze &operator=(const EnemyKamikaze &rhs);

	void onFire(World &world);
};

#endif
