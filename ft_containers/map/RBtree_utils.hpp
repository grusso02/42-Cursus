/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree_utils.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:29:55 by gabriele          #+#    #+#             */
/*   Updated: 2022/07/19 11:36:05 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	enum COLOR {
		RED,
		BLACK,
		FLUO
	};

	template <typename T>
	struct Node
	{
		T				data;
		Node<T>			*left, *right, *parent;
		bool			isLeftChild;
		enum COLOR		color;

		typedef T		value_type;
		bool isLeftChild() { return (parent && parent->left == this); }
		bool isRightChild() { return (parent && parent->right == this); }
		
		Node* sibling()
		{
			if (isLeftChild)
				return parent->right;
			if (isRightChild)
				return parent->left;
			return NULL;
		}

		Node* uncle()
		{
			if (parent)
				return parent->sibling;
			return NULL;
		}

		Node* grandparent()
		{
			if (parent)
				return parent->parent;
			return NULL;
		}
	};

	template<typename T, typename U>
	bool operator<(const ft::Node< ft::pair<T, U> >& lhs, const ft::Node< ft::pair<T, U> >& rhs)
	{
		return lhs.first < rhs.second;
	};
} // namespace ft