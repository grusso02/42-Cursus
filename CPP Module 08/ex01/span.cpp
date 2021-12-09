/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:21:48 by grusso            #+#    #+#             */
/*   Updated: 2021/12/09 16:53:26 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "span.hpp"
#include <iostream>

Span::Span() : n(0), array(0) {}

Span::Span(unsigned int _n) : n(_n) {}

Span::Span(const Span& src)
{
	this->operator=(src);
}

Span::~Span() {}

Span& Span::operator=(const Span& src)
{
	n = src.n;
	array = src.array;

	return (*this);
}

void	Span::addNumber(int x)
{
	if (array.size() < n)
		array.push_back(x);
	else
		throw Span::OverflowArray();
}

void	Span::addNumber(int begin, int end)
{
	if ((begin > end) || (array.size() + (end - begin) > n))
		throw Span::OverflowArray();
	else
		for (int i = begin; i <= end; i++)
			array.push_back(i);
}

int		Span::shortestSpan()
{
	if (array.size() < 2)
		Span::BadArgArray();
	int ret = std::abs(array[1] - array[0]);
	int min = 0;
	std::sort(array.begin(), array.end());
	for (std::size_t i = 1; i < array.size(); i++)
	{
		min = std::abs(array[i - 1] - array[i]);
		ret = (min > ret) ? ret : min;
	}
	return ret;
}

int		Span::longestSpan()
{
	if (array.size() < 2)
		Span::BadArgArray();
	int min = *std::min_element(array.begin(), array.end());
	int max = *std::max_element(array.begin(), array.end());
	return (max - min);
}