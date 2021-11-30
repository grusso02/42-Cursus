/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:54:52 by grusso            #+#    #+#             */
/*   Updated: 2021/11/30 16:26:24 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() 
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];

	std::cout << "Brain Copy Constuctor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];

	return (*this);	
}