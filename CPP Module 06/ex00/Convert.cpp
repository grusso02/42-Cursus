/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:40:45 by grusso            #+#    #+#             */
/*   Updated: 2021/12/06 19:45:42 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string str) : _str(str)
{
    std::size_t found = 0;

	if ((found = _str.find(".")) != std::string::npos)
	{
		if (((found + 1) == _str.size() - 1) && (_str[_str.size() - 1] == '0'))
			flag = ZERO;
		if ((found = _str.find("f", _str.size() - 1)) != std::string::npos)
			flag = FLOAT;
		else
			flag = DOUBLE;
	}
	if (_str[_str.size()] == '\0' && _str[_str.size() - 1] == '0' && _str[_str.size() - 2] == '.')
		flag = INT;
	if (_str[_str.size() - 1] == 'f' && _str[_str.size() - 2] == '0' && _str[_str.size() - 3] == '.')
		flag = INT;
    else if (((_str[0] >= 32 && _str[0] <= 47) || (_str[0] >= 58 && _str[0] <= 126)) && str.size() == 1)
		flag = CHAR;
	else
		flag = INT;
    if (flag == CHAR)
        c = _str[0];
	else
		nb = strtod(_str.c_str(), 0);
}

Convert::~Convert() {}

void    Convert::toChar() const
{
    std::cout << "char: ";

    if (_str == "nan" || _str == "inf" || _str == "+inf" || _str == "-inf")
        std::cout << "impossible" << std::endl;
    else if (_str == "nanf" || _str == "inff" || _str == "+inff" || _str == "-inff")
        std::cout << "impossible" << std::endl;
	else if (flag == CHAR)
		std::cout << "'" << c << "'" << std::endl;
    else if (nb > 127 && nb < -128)
        std::cout << "overflow" << std::endl;
	else if ((nb >= 0 && nb < ' ') || nb == 127)
		std::cout << "Non displayable" << std::endl;
	else if (nb >= -128 && nb <= 126)
		std::cout << "'" << static_cast<char>(nb) << "'" << std::endl;
}

void    Convert::toInt() const
{
    std::cout << "int: ";

    if (_str == "nan" || _str == "inf" || _str == "+inf" || _str == "-inf")
        std::cout << "impossible" << std::endl;
    else if (_str == "nanf" || _str == "inff" || _str == "+inff" || _str == "-inff")
        std::cout << "impossible" << std::endl;
	else if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
		std::cout << "overflow" << std::endl;
	else if (flag == CHAR)
		std::cout << static_cast<int>(c) << std::endl;
	else
		std::cout << static_cast<int>(nb) << std::endl;
}

void    Convert::toFloat() const
{
    std::cout << "float: ";

    if (_str == "nan" || _str == "inf" || _str == "+inf" || _str == "-inf")
        std::cout << _str << "f" << std::endl;
    else if (_str == "nanf" || _str == "inff" || _str == "+inff" || _str == "-inff")
        std::cout << _str << std::endl;
	else if (flag == ZERO)
		std::cout << static_cast<float>(nb) << ".0" << std::endl;
	else if (flag == INT)
		std::cout << static_cast<float>(nb) << ".0f" << std::endl;
	else if (flag == CHAR)
		std::cout << static_cast<int>(c) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(nb) << "f" << std::endl;
}

void    Convert::toDouble() const
{
    std::cout << "double: ";

    if (_str == "nan" || _str == "inf" || _str == "+inf" || _str == "-inf")
        std::cout << _str << std::endl;
    else if (_str == "nanf" || _str == "inff" || _str == "+inff" || _str == "-inff")
        std::cout << _str.substr(0, _str.size() - 1) << _str << std::endl;
	else if (flag == ZERO)
		std::cout << static_cast<double>(nb) << ".0" << std::endl;
	else if (flag == INT)
		std::cout << static_cast<double>(nb) << ".0" << std::endl;
	else if (flag == CHAR)
		std::cout << static_cast<int>(c) << ".0" << std::endl;
	else
		std::cout << static_cast<double>(nb) << std::endl;
}

std::ostream& operator<<(std::ostream& os, Convert const& convert)
{
    convert.toChar();
    convert.toInt();
    convert.toFloat();
    convert.toDouble();

    return (os);
}