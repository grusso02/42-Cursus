/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:11:20 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 16:10:44 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("")
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

ClapTrap::~ClapTrap()
{
	std::cout << _name << " ran away" << std::endl;
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
	<< " has absorbed " << amount << " energy points" << std::endl;
}