/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:56:04 by grusso            #+#    #+#             */
/*   Updated: 2021/11/27 20:25:15 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap p1("De Luca");

	p1.attack("Mario Giordano");
	p1.takeDamage(20);
	p1.beRepaired(15);
	p1.guardGate();
	p1.highFivesGuys();
	p1.whoAmI();

	return 0;
}