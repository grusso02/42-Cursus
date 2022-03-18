/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:47:58 by grusso            #+#    #+#             */
/*   Updated: 2022/03/18 12:14:38 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <__tree>


int main()
{
	std::map<char,int> map;
	pair<char, int> p1('k', 1);
	map.insert(p1);

	std::map<char, int>::iterator it;
	it = map.begin();
}