/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:06 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 19:49:17 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat was created" << std::endl;
}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	_brain = new Brain();
	*_brain = *other._brain; 
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat was destroyed" << std::endl;
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

std::string	Cat::getType() const
{
	return (_type);
}

void		Cat::makeSound() const
{
	std::cout << "Miao!" << std::endl;
}