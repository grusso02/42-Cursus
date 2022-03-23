/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:32:59 by grusso            #+#    #+#             */
/*   Updated: 2022/03/23 17:31:25 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

	struct Node
	{
		int data;
		Node *parent;
		Node *left;
		Node *right;
		int color;
		Node() : data(0), parent(nullptr), left(nullptr), right(nullptr), color(0) {}
	};

	typedef Node *NodePtr;

	class _tree
	{
		_tree()
		{
			TNULL = new Node;
    		TNULL->color = 0;
			TNULL->left = nullptr;
    		TNULL->right = nullptr;
    		root = TNULL;
		}
		~_tree() {}

		private:
			NodePtr root;
			NodePtr TNULL;
	};
	

} // namespace ft
