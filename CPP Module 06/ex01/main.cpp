/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:57:21 by grusso            #+#    #+#             */
/*   Updated: 2021/12/06 20:35:21 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctime>

struct Data
{
	int nb;
};

uintptr_t	serialize(Data* ptr)
{
	srand(time(0));
	ptr->nb = rand() % 100;
	std::cout << "Serialize" << std::endl;
	std::cout << "Numero: " << ptr->nb << std::endl;

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data*		data;
	Data*		data2;
	uintptr_t	raw = 0;
 
	raw = serialize(data);
	data2 = deserialize(raw);

	std::cout << "Deserialize" << std::endl;
	std::cout << "Numero: " << data2->nb << std::endl;

	return 0;
}
