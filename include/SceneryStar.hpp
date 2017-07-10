/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneryStar.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcasino <justincasino@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:27:01 by jcasino           #+#    #+#             */
/*   Updated: 2017/07/09 20:31:32 by jcasino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERYSTAR_HPP
# define SCENERYSTAR_HPP

class SceneryStar : public Scenery
{
public:
	SceneryStar(const char *icon, int16_t x, int16_t y, unint16_t w, uint16_h);
	SceneryStar(const Scenery &copy);
	~SceneryStar();

	SceneryStar &operator=(const Scenery &rhs);

};

#endif
