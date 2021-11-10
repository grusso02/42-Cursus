/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:04:09 by gabriele          #+#    #+#             */
/*   Updated: 2021/10/28 17:00:21 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	class_phonebook::set_firstName(std::string s)
{
	return (s);
}

std::string	class_phonebook::set_lastName(std::string s)
{
	return (s);
}

std::string	class_phonebook::set_nickname(std::string s)
{
	return (s);
}

std::string	class_phonebook::set_phoneNumber(std::string s)
{
	return (s);
}

std::string	class_phonebook::set_darkestSecret(std::string s)
{
	return (s);
}

std::string	class_phonebook::ft_substr(std::string s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + '.');
	else
		return (s);
}