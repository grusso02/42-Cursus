/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:37:41 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 20:28:00 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("defaut_clap_name"), ScavTrap("default"), FragTrap("default"), _name("default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " escaped from the laboratory" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " escaped from the laboratory" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other)
{
	std::cout << "DiamondTrap " << _name << " was copied" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " exploded" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &other)
{
	if (this != &other) {
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap " << _name << " was copied from " << other._name << std::endl;
	return *this;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name: " << _name
	<< "\tMy ClapTrap name: " << ClapTrap::_name << std::endl;
} 