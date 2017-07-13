/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Healthy.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:02:49 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/13 15:09:55 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEALTHY_HPP
# define HEALTHY_HPP
# include "Entity.hpp"
# include "World.hpp"

class Healthy
{
public:
	uint8_t hp;

	virtual bool onHit(World &, Entity &)
	{
		return (hp-- > 0);
	}
};

#endif
