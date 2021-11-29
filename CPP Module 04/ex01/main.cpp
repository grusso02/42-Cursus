/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:34:26 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 19:57:11 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define N 2

int main()
{
	Animal* animals[N];

	std::cout << "-------Subject Test-------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n-------Loop Test-------" << std::endl;
	for (int i = 0; i < N; i++)
	{
		if (i < (N / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << animals[i]->getType() << std::endl;
	}
	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << "\n-------Copy Test-------" << std::endl;
	Cat pallina;
	Dog birillo;
}
