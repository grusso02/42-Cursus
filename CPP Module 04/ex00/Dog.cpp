/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:09 by grusso            #+#    #+#             */
/*   Updated: 2021/11/30 16:54:02 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->_type = other._type;

	return (*this);
}

void		Dog::makeSound() const
{
	std::cout << "Bau!" << std::endl;
}