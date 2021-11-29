/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:09 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 19:49:27 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog was created" << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	_brain = new Brain();
	*_brain = *other._brain;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog was destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*_brain = *other._brain; 
	}

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