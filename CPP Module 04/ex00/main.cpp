/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:34:26 by grusso            #+#    #+#             */
/*   Updated: 2021/11/29 18:44:12 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "-------Wrong Cat-------" << std::endl;

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* cat_wr = new WrongCat();

	std::cout << cat_wr->getType() << std::endl;
	metaWrong->makeSound();
	cat_wr->makeSound();
	delete metaWrong;
	delete cat_wr;
}
