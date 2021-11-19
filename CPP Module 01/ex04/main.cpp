/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:28:48 by grusso            #+#    #+#             */
/*   Updated: 2021/11/19 17:01:46 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	takeInput(std::string& _fileName, std::string& s1, std::string& s2)
{
	std::cout << "File name: ";
	std::getline(std::cin, _fileName);
	std::cout << "First string: ";
	std::getline(std::cin, s1);
	std::cout << "Second string: ";
	std::getline(std::cin, s2);
}

int main()
{
	std::string		_fileName, s1, s2;
	std::string		strTemp;

	takeInput(_fileName, s1, s2);
	std::string out = _fileName;
	out += ".replace";

	std::ifstream	fdIn(_fileName);
	std::ofstream	fdOut(out);
	
	if (fdIn.fail() || fdOut.fail())
		return (EXIT_FAILURE);

	std::getline(fdIn, strTemp, '\0');
	fdIn.close();

	size_t			n = 0;
	while ((n = strTemp.find(s1)) != std::string::npos)
	{
		strTemp.erase(n, s1.size());
		strTemp.insert(n, s2);
	}

	fdOut << strTemp;
	fdOut.close();
	return 0;
}
