/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneryOrb.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:27:01 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 20:31:57 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERYORB_HPP
# define SCENERYORB_HPP

class SceneryOrb : public Scenery
{
public:
	SceneryOrb(const char *icon, int16_t x, int16_t y, unint16_t w, uint16_h);
	SceneryOrb(const Scenery &copy);
	~SceneryOrb();

	SceneryOrb &operator=(const SceneryOrb &rhs);

};

#endif
