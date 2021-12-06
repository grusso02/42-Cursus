/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:46:16 by grusso            #+#    #+#             */
/*   Updated: 2021/12/06 21:16:06 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(time(0));
	Base *ptr = nullptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return 0;
}
