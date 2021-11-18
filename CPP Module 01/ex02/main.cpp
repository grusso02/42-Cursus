/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:53:33 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 17:10:29 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "String address:\t\t\t" << &str << std::endl;
	std::cout << "String address by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "String address by stringREF:\t" << &stringREF << std::endl;
	std::cout << "String by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "String by stringREF:\t\t" << stringREF << std::endl;

	return 0;
}
