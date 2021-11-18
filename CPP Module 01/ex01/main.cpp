/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:15:15 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 16:48:07 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombies = zombieHorde(5, "Mario");

	for (int i = 0; i < 5; i++)
		zombies[i].announce();

	delete[](zombies);
	return (0);
}
