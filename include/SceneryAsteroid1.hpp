/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneryAsteroid1.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:27:01 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 18:27:03 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERYASTEROID1_HPP
# define SCENERYASTEROID_HPP

class SceneryAsteroid1 : public Scenery
{
public:
	SceneryAsteroid1(const char *icon, int16_t x, int16_t y, unint16_t w, uint16_h);
	SceneryAsteroid1(const Scenery &copy);
	~ScceneryAsteroid1();

	SceneryAstroid1 &operator=(const SceneryAsteroid1 &rhs);

};

#endif
