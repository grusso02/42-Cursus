/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:49:10 by grusso            #+#    #+#             */
/*   Updated: 2021/11/30 18:22:53 by grusso           ###   ########.fr       */
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
