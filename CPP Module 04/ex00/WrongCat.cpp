/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:32:57 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 19:01:47 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->_type = other._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat was destroyed" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		this->_type = other._type;

	return (*this);
}

std::string	WrongCat::getType() const
{
	return (_type);
}

void		WrongCat::makeSound() const
{
	std::cout << "Wrong Miao!" << std::endl;
}