/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:09 by grusso            #+#    #+#             */
/*   Updated: 2021/11/30 16:32:29 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
	//std::cout << "Dog Brain Address: " << &_brain << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	_brain = new Brain();
	*_brain = *other._brain;
	std::cout << "Dog Copy Constructor called" << std::endl;
	//std::cout << "Dog Copy Brain Address: " << &_brain << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

std::string	Dog::getType() const
{
	return (_type);
}

void		Dog::makeSound() const
{
	std::cout << "Bau!" << std::endl;
}

Brain*		Dog::getBrain() const
{
	return (_brain);
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
