/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:03:20 by grusso            #+#    #+#             */
/*   Updated: 2021/11/18 15:55:48 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	/***********Heap memory***********/
	Zombie *zombie = NULL;

	zombie = newZombie("Ignazio");
	zombie->announce();

	/***********Stack memory***********/
	randomChump("Valentino");

	delete zombie;
	return (0);
}
