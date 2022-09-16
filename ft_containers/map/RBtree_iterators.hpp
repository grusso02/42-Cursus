/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:47:07 by gabriele          #+#    #+#             */
/*   Updated: 2022/07/22 11:53:11 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils.hpp"
#include "../iterator.hpp"
#include "./RBtree_utils.hpp"

namespace ft
{
	template <class T, class Compare = ft::less<T>, bool enableConstConstructor = false >
	class rbt_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		
	};
	
} // namespace ft