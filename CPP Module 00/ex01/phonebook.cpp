/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:37:52 by gabriele          #+#    #+#             */
/*   Updated: 2021/10/28 16:59:37 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	class_phonebook::ft_search()
{
	std::string	index;
	int			idx;

	std::cout << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << std::endl;

	for (int j = 0; contacts[j].first_name > "\0" ; j++)
	{
		std::cout << std::setw(10) << j;
		std::cout << "|" << std::setw(10) << ft_substr(contacts[j].first_name);
		std::cout << "|" << std::setw(10) << ft_substr(contacts[j].last_name);
		std::cout << "|" << std::setw(10) << ft_substr(contacts[j].nickname) << std::endl;
	}

	while (1)
	{
		std::cout << RED("Insert the index of the contact to view") << std::endl;
		std::getline(std::cin, index);
		if (index.length() == 1 && index >= "0" && index <= "8")
		{
			idx = std::stoi(index);
			std::cout << CYAN("First name:\t\t") << contacts[idx].first_name << std::endl;
			std::cout << CYAN("Last name:\t\t") << contacts[idx].last_name << std::endl;
			std::cout << CYAN("Nickname:\t\t") << contacts[idx].nickname << std::endl;
			std::cout << CYAN("Phone number:\t\t") << contacts[idx].phone_number << std::endl;
			std::cout << CYAN("Darkest Secret:\t\t") << contacts[idx].darkest_secret << std::endl;
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
	contacts[i].first_name = set_firstName(str);

	std::cout << RED("Last name") << std::endl;
	std::getline(std::cin, str);
	contacts[i].last_name = set_lastName(str);

	std::cout << RED("Nickname") << std::endl;
	std::getline(std::cin, str);
	contacts[i].nickname = set_nickname(str);

	std::cout << RED("Phone number") << std::endl;
	std::getline(std::cin, str);
	contacts[i].phone_number = set_phoneNumber(str);

	std::cout << RED("Darkest secret") << std::endl;
	std::getline(std::cin, str);
	contacts[i].darkest_secret = set_darkestSecret(str);
	std::cout << GREEN("CONTACT ADDED!") << std::endl;
	i++;
}

int	main()
{
	std::string	command;
	class_phonebook	phonebook = class_phonebook();

	while (1)
	{
		std::cout << RED("Insert a command: ADD, SEARCH or EXIT") << std::endl;
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