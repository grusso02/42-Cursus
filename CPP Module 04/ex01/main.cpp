/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:34:26 by grusso            #+#    #+#             */
/*   Updated: 2021/11/30 16:23:07 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define N 2

int main()
{
	Animal* animals[N];
	Brain*	brain;

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

	brain = pallina.getBrain();
	brain->_ideas[0] = "Idea 1";
	brain->_ideas[1] = "Idea 2";
	brain->_ideas[2] = "Idea 3";

	std::cout << pallina.getBrain()->_ideas[0] << std::endl;

	Cat copy(pallina);
	std::cout << copy.getBrain()->_ideas[0] << std::endl;
}
