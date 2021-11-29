/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:30:08 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 18:30:59 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->_type = other._type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was destroyed" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong silence" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->_type = other._type;

	return (*this);
}