/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:30:50 by grusso            #+#    #+#             */
/*   Updated: 2021/11/19 15:27:52 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}