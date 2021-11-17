/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:04:22 by grusso            #+#    #+#             */
/*   Updated: 2021/11/17 19:01:42 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name);

	return (zombie);
}

void	Zombie::announce(void)
{
	std::cout << nameZombie << " BraiiiiiiinnnzzzZ..." << std::endl;
}