/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:35:29 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 18:19:08 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal was created" << std::endl;
}

Animal::Animal(const Animal& other)
{
	this->_type = other._type;
}

Animal::~Animal()
{
	std::cout << "Animal was destroyed" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Silence" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;

	return (*this);
}