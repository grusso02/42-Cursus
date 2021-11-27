/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:16:51 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 20:11:04 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

# define HIT_POINTS		100
# define ENERGY_POINTS	50
# define ATTACK_DAMAGE	20

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "ScavTrap " << _name << " emerged from the sea" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << "ScavTrap " << _name << " emerged from the sea" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " was copied" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " is back to swim among the fish" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap " << _name << " was copied from " << other._name << std::endl;

	return *this;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << _name
	<< " used SURF on " << target << ", causing " << _attackDamage
	<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name
	<< " has enterred in Gate keeper mode" << std::endl;
}