/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:58 by grusso            #+#    #+#             */
/*   Updated: 2021/12/06 19:47:13 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	ft_parsing(std::string str)
{
	std::size_t found = 0;

	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
		return 0;
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
		return 0;
	if (str[0] >= 32 && str[0] <= 126 && str.size() == 1)
		return 0;

	if ((found = str.find('.')) != std::string::npos)
		if ((found = str.find('.', found + 1)) != std::string::npos) //controllo eventuali punti doppi
			return 1;

	for (std::size_t i = 0; i < str.size() - 1; i++) //per ogni char (tranne l'ultimo) controllo se é un digit o un punto
		if (!isdigit(str[i]) && str[i] != '.')
		{
			if (i == 0 && str[i] == '-')
				continue ;
			else
				return 1;
		}

	if (str[str.size() - 1] != 'f' && !isdigit(str[str.size() - 1])) //se ultimo caratte != da f && != da un digit
		return 1;

	return (0);
}

int main(int argc, char *argv[])
{
	if (argc != 2 || ft_parsing(argv[1]))
	{
		std::cout << "Bad parameters" << std::endl;
		return 1;
	}

	Convert nb(argv[1]);
	std::cout << nb;

	return 0;
}
