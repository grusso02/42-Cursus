/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:11:20 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 18:00:06 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

# define HIT_POINTS		10
# define ENERGY_POINTS	10
# define ATTACK_DAMAGE	10

ClapTrap::ClapTrap() : _name("default")
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << _name << " landed on Earth" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_hitPoints = HIT_POINTS;
	_energyPoints = ENERGY_POINTS;
	_attackDamage = ATTACK_DAMAGE;
	std::cout << _name << " landed on Earth" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << _name << " was copied" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " ran away" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " was copied from " << other._name << std::endl;

	return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << _name
	<< " used DOUBLESLAP on " << target << ", causing " << _attackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name
	<< " took " << amount << " damage points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name
	<< " has absorbed " << amount << " hit points" << std::endl;
}
