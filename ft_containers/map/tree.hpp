/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:40 by grusso            #+#    #+#             */
/*   Updated: 2022/03/24 18:13:27 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# define BLACK	0
# define RED	1

template <typename T>
struct Node
{
	typedef T							value_type;
	typedef value_type					second_type;
	typedef T*							pointer;
	typedef T&							reference;
	typedef bidirectional_iterator_tag	iterator_category;
	typedef	ptrdiff_t					difference_type;

	struct Node<T>	*left, *right;
	struct Node<T>	*parent;
	bool			color;
	value_type		data;

	Node() : left(nullptr), right(nullptr), parent(nullptr), color(BLACK), data(0) {}
	Node(T _data) : left(nullptr), right(nullptr), parent(nullptr), color(BLACK), data(_data) {}
};

template <class T, class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Node<T> > >
class _tree
{
	public:
		typedef Node<T>												_node;
		typedef node												_nodePtr;
		typedef typename node::value_type							node_value;
		typedef typename node::second_type							mapped_type;
		typedef Alloc												allocator_type;
		typedef Compare												key_compare;
		typedef key_compare											value_compare;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::value_type					value_type;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef typename allocator_type::size_type					size_type;
		typedef typename allocator_type::difference_type			difference_type;
	
		void insert(int key)
		{
			_nodePtr node = new _node(key);

			_nodePtr y = nullptr;
			_nodePtr x = this->root;

			while (x != TNULL)
			{
				y = x;
				if (node->data < x->data)
					x = x->left;
				else
					x = x->right;
			}

			node->parent = y;
			if (y == nullptr) {
			root = node;
			} else if (node->data < y->data) {
			y->left = node;
			} else {
			y->right = node;
			}

			if (node->parent == nullptr) {
			node->color = 0;
			return;
			}

			if (node->parent->parent == nullptr) {
			return;
			}

			insertFix(node);
  		}

		_tree(/* args */);
		~_tree();

		private:
			_nodePtr	root;
};


#endif