/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:47:48 by grusso            #+#    #+#             */
/*   Updated: 2021/12/09 16:18:59 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>

int main()
{
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i + 1);
	if (easyfind(a, 5))
		std::cout << "Elemento trovato in una struttura VECTOR" << std::endl;
	else
		std::cout << "Elemento non trovato in una struttura VECTOR" << std::endl;
	if (easyfind(a, 50))
		std::cout << "Elemento trovato in una struttura VECTOR" << std::endl;
	else
		std::cout << "Elemento non trovato in una struttura VECTOR" << std::endl;

	std::cout << "------------------------------------------------" << std::endl;

	std::list<int> b;
	for (int i = 0; i < 10; i++)
		b.push_back(i + 1);
	if (easyfind(a, 5))
		std::cout << "Elemento trovato in una struttura LIST" << std::endl;
	else
		std::cout << "Elemento non trovato in una struttura LIST" << std::endl;
	if (easyfind(a, 50))
		std::cout << "Elemento trovato in una struttura LIST" << std::endl;
	else
		std::cout << "Elemento non trovato in una struttura LIST" << std::endl;
}