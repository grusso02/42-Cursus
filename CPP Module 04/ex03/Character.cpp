/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:02:24 by grusso            #+#    #+#             */
/*   Updated: 2021/12/01 17:53:07 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : ICharacter(), _name(name), _inventory(new AMateria*[INV_SIZE])
{
	for (int i = 0; i < INV_SIZE; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	for (int i = 0; i < INV_SIZE; i++)
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
}

Character::~Character() 
{
	for (int i = 0; i < INV_SIZE; i++)
		if (_inventory[i])
			delete _inventory[i];
	delete [] _inventory;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		for (int i = 0; i < INV_SIZE; i++)
			if (_inventory[i])
				delete _inventory[i];
		for (int i = 0; i < INV_SIZE; i++)
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	for (; i < INV_SIZE && _inventory[i]; i++)
		;

	if (i == INV_SIZE)
		return ;

	_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	_inventory[idx]->use(target);
}