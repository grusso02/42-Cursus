/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:57:52 by gabriele          #+#    #+#             */
/*   Updated: 2021/11/26 19:22:08 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const Point& other)
{
	*this = other;
}

Point::Point(const Fixed _x, const Fixed _y) : x(_x), y(_y) {}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}