/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:04:41 by grusso            #+#    #+#             */
/*   Updated: 2021/12/09 17:28:04 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src) : std::stack<T>(src) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
	return (std::stack<T>::operator=(src));
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}