/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:11:23 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 16:05:17 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap p1("De Luca");

	p1.attack("Mario Giordano");
	p1.takeDamage(20);
	p1.beRepaired(15);
	return 0;
}
