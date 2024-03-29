/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:49:10 by grusso            #+#    #+#             */
/*   Updated: 2021/12/01 19:00:19 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other)
{
	_type = other._type;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other) {}

	return (*this);
}
