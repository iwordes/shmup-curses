/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:36:48 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/07 23:00:09 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

class Entity
{
public:
	char *layer;
	uint16_t w;
	uint16_t h;
	uint16_t d;

	uint16_t x;
	uint16_t y;

	virtual void onTick();
};

#endif
