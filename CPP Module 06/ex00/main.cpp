/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:58 by grusso            #+#    #+#             */
/*   Updated: 2021/12/03 19:35:36 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

int main()
{
	std::string str;

	str = "0";
	std::stringstream intTicket(str);

	int ticketNumber = 0;
	intTicket >> ticketNumber;

	std::cout << "Ticket number: " << (char)ticketNumber;

	return 0;
}
