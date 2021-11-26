/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:47:55 by gabriele          #+#    #+#             */
/*   Updated: 2021/11/26 18:29:05 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fract = 8;

Fixed::Fixed() : rawBits(0) 
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	rawBits = n << fract;
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called" << std::endl;
	rawBits = (int)roundf(n * (1 << fract));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	rawBits = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		rawBits = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	ret;

	ret.setRawBits(getRawBits() + other.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	ret;

	ret.setRawBits(getRawBits() - other.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	ret;

	ret.setRawBits((getRawBits() * other.getRawBits()) >> fract);
	return (ret);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	ret;

	ret.setRawBits((getRawBits() / other.getRawBits()) << fract);
	return (ret);
}

Fixed&	Fixed::operator++()
{
	++rawBits;

	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	++rawBits;
	return (old);
}

Fixed&	Fixed::operator--()
{
	--rawBits;

	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	--rawBits;
	return (old);
}

Fixed&	Fixed::min(Fixed& x, Fixed& y)
{
	return (x < y ? x : y);
}

Fixed&	Fixed::max(Fixed& x, Fixed& y)
{
	return (x > y ? x : y);
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y)
{
	return (x < y ? x : y);
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y)
{
	return (x > y ? x : y);
}

float	Fixed::toFloat(void) const
{
	return ((float)rawBits / (float)(1 << fract));
}

int	Fixed::toInt(void) const
{
	return ((int)(rawBits >> fract));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}