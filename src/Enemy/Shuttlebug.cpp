/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shuttlebug.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwordes <iwordes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:31:07 by iwordes           #+#    #+#             */
/*   Updated: 2017/07/09 19:36:56 by iwordes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <EnemyShuttlebug.hpp>



void EnemyShuttlebug::onTick(World &world)
{
	if (tt < 10)
		// ...
	else if (tt < 20)
		// ...
	else if (tt < 30)
		// ...
	else if (tt < 40)
		// ...
	else
		tt = 0;
	tt++;
}
