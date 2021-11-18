/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:15:25 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 16:44:30 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	_nameZombie = "";
}

Zombie::~Zombie()
{
	std::cout << _nameZombie << " is dead" << std::endl;
}

void	Zombie::setName(std::string name)
{
	_nameZombie = name;
}

std::string	Zombie::getName()
{
	return (_nameZombie);
}

void	Zombie::announce(void)
{
	std::cout << "<" << getName() << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}