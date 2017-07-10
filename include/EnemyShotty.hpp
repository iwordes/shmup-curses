/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShotty.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:47:11 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 21:50:44 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYSHOTTY_HPP
# define ENEMYSHOTTY_HPP

# include "Enemy.hpp"

class EnemyShotty: public Enemy
{
public:
	EnemyShotty(int16_t x = 0, int16_t y = 0);
	EnemyShotty(const EnemyShotty &);
	~EnemyShotty();

	EnemyShotty &operator=(const EnemyShotty &);

	void onFire(World &world);
};

#endif
