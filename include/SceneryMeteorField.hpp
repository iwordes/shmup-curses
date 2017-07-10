/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneryMeteorField.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:27:01 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 20:32:19 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERYMETEORFIELD_HPP
# define SCENERYMETEORFIELD_HPP

class SceneryMeteorField : public Scenery
{
public:
	SceneryMeteorField(const char *icon, int16_t x, int16_t y, unint16_t w, uint16_h);
	SceneryMeteorField(const Scenery &copy);
	~SceneryMeteorField();

	SceneryMeteorField &operator=(const SceneryMeteorField &rhs);

};

#endif
