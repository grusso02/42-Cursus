/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:37:34 by gabriele          #+#    #+#             */
/*   Updated: 2021/11/17 15:34:47 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string	str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			str += argv[i];
		for (int j = 0; str[j] > '\0'; j++)
			if (str[j] >= 'a' && str[j] <= 'z')
				str[j] -= 32;
		std::cout << str << std::endl;
	}
	return (0);
}