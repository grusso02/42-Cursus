/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:28:28 by grusso            #+#    #+#             */
/*   Updated: 2021/12/07 17:45:17 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
	char		c[] = "abcdefghijklmnopqrstuvwxyz";
	int			n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string	s[] = {"hello", "world"};

	std::cout << "Test:\t Char" << std::endl;
	iter(c, 26, ft_print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test:\t Int" << std::endl;
	iter(n, 9, ft_print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Test:\t String" << std::endl;
	iter(s, 2, ft_print);
	std::cout << std::endl;
	std::cout << std::endl;
}