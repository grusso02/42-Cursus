/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:06 by grusso            #+#    #+#             */
/*   Updated: 2021/11/30 16:56:28 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
	//std::cout << "Cat Brain Address: " << &_brain << std::endl;
}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	_brain = new Brain();
	*_brain = *other._brain;
	std::cout << "Cat Copy Constructor called" << std::endl;
	//std::cout << "Cat Copy Brain Address: " << &_brain << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void		Cat::makeSound() const
{
	std::cout << "Miao!" << std::endl;
}

Brain*		Cat::getBrain() const
{
	return (_brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		_type = other._type;
		*_brain = *other._brain; 
	}

	return (*this);
}
