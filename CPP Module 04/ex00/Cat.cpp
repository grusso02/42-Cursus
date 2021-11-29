/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:29:06 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 19:00:52 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat was created" << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
}

Cat::~Cat()
{
	std::cout << "Cat was destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->_type = other._type;

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