/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenery.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:40:04 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 18:40:05 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERY_HPP
# define SCENERY_HPP

class Scenery
{
public:
	Sceneryconst char *icon, int16_t x, int16_t y, unint16_t w, uint16_h);
	Scenery(const Scenery &copy);
	~Sccenery();

	Scenery &operator=(const SceneryAsteroid &rhs);


	virtual bool onHit(World &, Entity &);

};

#endif
