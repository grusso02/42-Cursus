/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:13:14 by grusso            #+#    #+#             */
/*   Updated: 2021/11/19 18:11:22 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char const *argv[])
{
	Karen karen;

	if (argc > 2)
		return (EXIT_FAILURE);

	karen.complain(argv[1]);

	return 0;
}
