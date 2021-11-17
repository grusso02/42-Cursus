/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:03:20 by grusso            #+#    #+#             */
/*   Updated: 2021/11/17 19:16:26 by grusso           ###   ########.fr       */
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

int main()
{
	Zombie *zombie = NULL;

	zombie = zombie->newZombie("Morgana");
	zombie->announce();
	delete zombie;
	return (0);
}
