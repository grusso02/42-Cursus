/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:41 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 19:44:14 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : _type("") {}

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

void	Weapon::setType(std::string str)
{
	_type = str;
}

const std::string&	Weapon::getType()
{
	return (_type);
}