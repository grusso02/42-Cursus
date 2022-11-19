/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree_utils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:29:55 by gabriele          #+#    #+#             */
/*   Updated: 2022/11/19 16:50:46 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class pair> //---> riceve gia la coppia (ft::pair(key, mapped value))
	struct Node
	{
		typedef Node<pair>*				node_pointer;
		typedef const Node<pair>*		const_node_pointer;
		node_pointer        			right;
		node_pointer        			left;
		node_pointer					parent;
		int 							empty_int_max_size;
		
		pair							_pair;

		Node() : right(NULL), left(NULL), parent(NULL), _pair(){}; // default
		Node(const pair& x) : right(NULL), left(NULL), parent(NULL), _pair(x){}; // with a pair
		Node(const Node& x) : right(x.right), left(x.left), parent(x.parent), _pair(x._pair){}; // copy
		~Node(){};
	};

	template<typename node_pointer>
	node_pointer next_node(node_pointer current)
	{
		if (current->parent == NULL && current->right != 0)
			return current->right;
		if ( current->parent != NULL && current->right != NULL)
		{
			current = current->right;
			while (current->parent != NULL && current->left != NULL)
				current = current->left;
			return current;
		}
		while (current->parent != NULL && current == current->parent->right)
			current = current->parent;
		if (current->parent != NULL)
		current = current->parent;
		return current;
	}
	
	template<typename node_pointer>
	node_pointer prev_node(node_pointer current)
	{
		if (current->parent == NULL && current->left != 0)
			return current->left;
		if (current->parent != NULL && current->left != NULL)
		{
			current = current->left;
			while (current->parent != NULL && current->right != NULL)
				current = current->right;
			return current;
		}
		while (current->parent != NULL && current == current->parent->left)
			current = current->parent;
		if (current->parent != NULL)
		current = current->parent;
		return current;
	}
} // namespace ft
