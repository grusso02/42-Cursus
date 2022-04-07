/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:40 by grusso            #+#    #+#             */
/*   Updated: 2022/04/05 16:18:20 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
struct Node
{
	T		value;
	Node<T>	*left, *right, *parent;
	bool	isLeftChild, isBlack;

	Node() : left(nullptr), right(nullptr), parent(nullptr), isLeftChild(false), isBlack(false) {}
	Node(T _value) : pair(value), left(nullptr), right(nullptr), parent(nullptr), isLeftChild(false), isBlack(false) {}
	~Node() {}
};

template < class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Value> >
class _tree
{
	public:
		typedef _Tp					value_type;
		typedef _Compare			value_compare;
		typedef _Allocator			allocator_type;
};
