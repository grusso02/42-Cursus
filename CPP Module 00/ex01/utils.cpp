/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:04:09 by gabriele          #+#    #+#             */
/*   Updated: 2021/11/17 12:33:04 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	class_phonebook::set_firstName(std::string s)
{
	contacts[i].first_name = s;
}

void	class_phonebook::set_lastName(std::string s)
{
	contacts[i].last_name = s;
}

void	class_phonebook::set_nickname(std::string s)
{
	contacts[i].nickname = s;
}

void	class_phonebook::set_phoneNumber(std::string s)
{
	contacts[i].phone_number = s;
}

void	class_phonebook::set_darkestSecret(std::string s)
{
	contacts[i].darkest_secret = s;
}

std::string	class_phonebook::get_firstName(int i)
{
	return (contacts[i].first_name);
}

std::string	class_phonebook::get_lastName(int i)
{
	return (contacts[i].last_name);
}

std::string	class_phonebook::get_nickname(int i)
{
	return (contacts[i].nickname);
}

std::string	class_phonebook::get_phoneNumber(int i)
{
	return (contacts[i].phone_number);
}

std::string	class_phonebook::get_darkestSecret(int i)
{
	return (contacts[i].darkest_secret);
}

std::string	class_phonebook::ft_substr(std::string s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + '.');
	else
		return (s);
}