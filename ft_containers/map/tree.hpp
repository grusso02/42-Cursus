/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:40 by grusso            #+#    #+#             */
/*   Updated: 2022/04/11 16:16:14 by grusso           ###   ########.fr       */
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

template < class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Node<Value> > >
class _tree
{
	public:
		typedef _Tp					value_type;
		typedef _Compare			value_compare;
		typedef _Allocator			allocator_type;

		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type       		size_type;
		typedef typename allocator_type::difference_type 		difference_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
};
