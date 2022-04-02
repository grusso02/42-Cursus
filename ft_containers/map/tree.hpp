/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:40 by grusso            #+#    #+#             */
/*   Updated: 2022/04/02 17:06:24 by gabriele         ###   ########.fr       */
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

template <class _Tp, class _Compare, class _Allocator>
class _tree
{
	
};
