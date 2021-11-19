/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:44 by grusso            #+#    #+#             */
/*   Updated: 2021/11/19 18:36:01 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
	_levels[0] = &Karen::debug;
	_levels[1] = &Karen::info;
	_levels[2] = &Karen::warning;
	_levels[3] = &Karen::error;
}

Karen::~Karen() {}

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI just love it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon cost more money.\nYou don’t put enough! If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string	ref[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; i < 4 && ref[i] != level;)
		i++;

	enum levels {DEBUG, INFO, WARNING, ERROR};
	switch (i)
	{
		case DEBUG:
			(this->*(_levels[DEBUG]))();
		case INFO:
			(this->*(_levels[INFO]))();
		case WARNING:
			(this->*(_levels[WARNING]))();
		case ERROR:
			(this->*(_levels[ERROR]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    		std::cout << std::endl;
			break;
	}
}