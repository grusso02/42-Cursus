/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:58:01 by gabriele          #+#    #+#             */
/*   Updated: 2021/11/27 18:31:00 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d[3];

	d[0] = (((point.getX() - a.getX()) * (c.getY() - a.getY())) - ((point.getY() - a.getY()) * (c.getX() - a.getX())));
	d[1] = (((a.getX() - point.getX()) * (b.getY() - a.getY())) - ((a.getY() - point.getY()) * (b.getX() - a.getX())));
	d[2] = (((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((b.getY() - a.getY()) * (c.getX() - a.getX())));

	Fixed _a(d[0] / d[2]);
	Fixed _b(d[1] / d[2]);

	return ((_a > 0) && (_b > 0) && ((_a + _b) < 1));
}