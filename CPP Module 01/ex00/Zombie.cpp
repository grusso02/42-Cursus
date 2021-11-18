/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:04:22 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 16:12:58 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	_nameZombie = "";
}

Zombie::Zombie(std::string name)
{
	_nameZombie = name;
}

Zombie::~Zombie()
{
	std::cout << _nameZombie << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << _nameZombie << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}