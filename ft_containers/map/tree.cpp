/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:59:15 by grusso            #+#    #+#             */
/*   Updated: 2022/03/25 16:51:24 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename K, typename V>
struct Node {
	K			key;
	V			value;
	Node<K, V>	left, right, parent;
	bool		isLeftChild, black;

	Node(K key, V value) {
		this->key = key;
		this->value = value;
		left = right = parent = NULL;
		black = false;
		isLeftChild = false;
	}
};

template <typename K, typename V>
class tree
{
	private:
		Node<K, V>	root;
		int			size;

	public:
		void	add(K key, V value) {
			Node<K, V> newNode(key, value) = new Node<K, V>;
			if (root == NULL) {
				root = newNode;
				root.black = true;
				size++;
				return ;
			}
			add(root, newNode);
			size++;
		}

	private:
		void	add(Node<K, V> parent, Node<K, V> newNode) {
			if (newNode.key >= parent.key) {
				if (paren.right == NULL) {
					parent.right = newNode;
					newNode.parent = parent;
					newNode.isLeftChild = false;
					return ;
				}
				return (add(parent.right, newNode));
			}
			if (parent.left == NULL) {
				parent.left = newNode;
				newNode.parent = parent;
				newNode.isLeftChild = true;
				return ;
			}
			return (add(parent.left, newNode));
			checkColor(newNode);
		}
};
