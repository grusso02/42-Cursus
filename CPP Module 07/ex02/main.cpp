/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:46:43 by grusso            #+#    #+#             */
/*   Updated: 2021/12/07 19:12:24 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> interi(10);
	for (int i = 0; i < 10; i++)
		interi[i] = i + 1;
	std::cout << "Array di " << interi.size() << " elementi INTERI:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << interi[i] << " ";
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------" << std::endl;

	Array<std::string> stringhe(10);
	std::string random[] = {"process", "start", "valid", "feature", "nationalism", "maze", "champagne", "printer", "account", "majority"};
	for (int i = 0; i < 10; i++)
		stringhe[i] = random[i];
	std::cout << "Array di " << stringhe.size() << " elementi STRINGHE:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << stringhe[i] << " ";
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------" << std::endl;

	Array<double> virgola(10);
	for (int i = 0; i < 10; i++)
		virgola[i] = i * 2.4;
	std::cout << "Array di " << virgola.size() << " elementi DOUBLE:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << virgola[i] << " ";
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Test con accesso negato:" << std::endl;
	Array<int> prova(2);
	for (int i = 0; i < 2; i++)
		prova[i] = i + 1;
	try
	{
		std::cout << prova[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
