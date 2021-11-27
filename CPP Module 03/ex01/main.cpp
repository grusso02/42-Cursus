/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:11:23 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 18:11:15 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap p1("De Luca");

	p1.attack("Mario Giordano");
	p1.takeDamage(20);
	p1.beRepaired(15);
	p1.guardGate();
	return 0;
}
