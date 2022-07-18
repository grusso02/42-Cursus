/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:40 by grusso            #+#    #+#             */
/*   Updated: 2022/07/18 14:46:12 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "../utils.hpp"

template <typename T>
struct Node
{
	T		data;
	Node<T>	*left, *right, *parent;
	bool	isLeftChild, isBlack;

	Node() : left(nullptr), right(nullptr), parent(nullptr), isLeftChild(false), isBlack(false) {}
	Node(T _value) : data(_value), left(nullptr), right(nullptr), parent(nullptr), isLeftChild(false), isBlack(false) {}
	~Node() {}
};

template <class T, class Compare = ft::less<Node<T> >, class Alloc = std::allocator<Node<T> > >
class RBtree
{
	public:
		typedef struct Node<T>	node;
		typedef T				value_type;
		typedef Compare			value_compare;
		typedef Alloc			allocator_type;

		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::size_type       		size_type;
		typedef typename allocator_type::difference_type 		difference_type;

		value_compare			_comp;

		RBtree() : _comp(), _root(NULL) {}
		RBTree(RBTree& tree): _comp(), _root(NULL)
		{
			*this = tree;
		}

	private:
		node*			_root;
		size_type		_size;
		allocator_type _allocator;

};
