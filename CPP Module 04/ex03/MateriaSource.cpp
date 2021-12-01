/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:01:51 by grusso            #+#    #+#             */
/*   Updated: 2021/12/01 18:35:39 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(), _knowMat(new AMateria*[MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++)
		_knowMat[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _knowMat(new AMateria*[MAT_SIZE])
{
	for (int i = 0; i < MAT_SIZE; i++)
		if (other._knowMat[i])
			_knowMat[i] = other._knowMat[i];
		else
			_knowMat[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MAT_SIZE; i++)
		if (_knowMat[i])
			delete _knowMat[i];
	delete [] _knowMat;
}

void		MateriaSource::learnMateria(AMateria* m)
{
	int	i = 0;

	for (; i < MAT_SIZE && _knowMat[i]; i++)
		;

	if (i == MAT_SIZE)
		return ;

	_knowMat[i] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAT_SIZE; i++)
		if (_knowMat[i]->getType() == type)
			return (_knowMat[i]->clone());

	return NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other) 
	{
		for (size_t i = 0; i < MAT_SIZE; i++)
			if (_knowMat[i])
				delete _knowMat[i];
		for (size_t i = 0; i < MAT_SIZE; i++)
			if (other._knowMat[i])
				_knowMat[i] = other._knowMat[i];
			else
				_knowMat[i] = NULL;
	}
	return *this;
}