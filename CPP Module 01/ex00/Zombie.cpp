/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:04:22 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 12:07:09 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	nameZombie = name;
}

Zombie::~Zombie()
{
	std::cout << nameZombie << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << nameZombie << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}