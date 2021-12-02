/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:24 by grusso            #+#    #+#             */
/*   Updated: 2021/12/02 17:12:39 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat joe = Bureaucrat("Joe", 1);
		std::cout << joe << std::endl;
		joe.decrGrade();
		std::cout << joe << std::endl;
		joe.incrGrade();
		std::cout << joe << std::endl;
		joe.incrGrade();
		std::cout << joe << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat jack = Bureaucrat("Jack", 150);
		std::cout << jack << std::endl;
		jack.incrGrade();
		std::cout << jack << std::endl;
		jack.decrGrade();
		std::cout << jack << std::endl;
		jack.decrGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
