/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:09 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 19:01:11 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog was created" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->_type = other._type;

	return (*this);
}

std::string	Dog::getType() const
{
	return (_type);
}

void		Dog::makeSound() const
{
	std::cout << "Bau!" << std::endl;
}