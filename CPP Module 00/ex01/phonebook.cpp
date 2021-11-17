/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:37:52 by gabriele          #+#    #+#             */
/*   Updated: 2021/11/17 15:35:28 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	class_phonebook::ft_search()
{
	std::string	index;
	int			idx;

	if (contacts[0].first_name == "\0")
	{
		std::cout << RED("THE PHONEBOOK IS EMPTY!") << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << std::endl;

	for (int j = 0; contacts[j].first_name > "\0" ; j++)
	{
		std::cout << std::setw(10) << j;
		std::cout << "|" << std::setw(10) << ft_substr(get_firstName(j));
		std::cout << "|" << std::setw(10) << ft_substr(get_lastName(j));
		std::cout << "|" << std::setw(10) << ft_substr(get_nickname(j)) << std::endl;
	}

	while (1)
	{
		std::cout << RED("Insert the index of the contact to view") << std::endl;
		std::getline(std::cin, index);
		if (index.length() == 1 && index >= "0" && index <= "8")
		{
			idx = std::stoi(index);
			std::cout << CYAN("First name:\t\t") << get_firstName(idx) << std::endl;
			std::cout << CYAN("Last name:\t\t") << get_lastName(idx) << std::endl;
			std::cout << CYAN("Nickname:\t\t") << get_nickname(idx) << std::endl;
			std::cout << CYAN("Phone number:\t\t") << get_phoneNumber(idx) << std::endl;
			std::cout << CYAN("Darkest Secret:\t\t") << get_darkestSecret(idx) << std::endl;
			break ;
		}
		else
			std::cout << RED("ERROR!") << std::endl;
	}
}

void	class_phonebook::ft_add()
{
	std::string	str;

	if (i == 8)
		i = 0;
	std::cout << RED("First name") << std::endl;
	std::getline(std::cin, str);
	set_firstName(str);

	std::cout << RED("Last name") << std::endl;
	std::getline(std::cin, str);
	set_lastName(str);

	std::cout << RED("Nickname") << std::endl;
	std::getline(std::cin, str);
	set_nickname(str);

	std::cout << RED("Phone number") << std::endl;
	std::getline(std::cin, str);
	set_phoneNumber(str);

	std::cout << RED("Darkest secret") << std::endl;
	std::getline(std::cin, str);
	set_darkestSecret(str);

	std::cout << GREEN("CONTACT ADDED!") << std::endl;
	i++;
}

int	main()
{
	std::string	command;
	class_phonebook	phonebook = class_phonebook();

	while (1)
	{
		std::cout << GREEN("Insert a command: ADD, SEARCH or EXIT") << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.ft_add();
		else if (command == "SEARCH")
			phonebook.ft_search();
		else
			std::cout << "Command unknown" << std::endl;
	}
	return (0);
}