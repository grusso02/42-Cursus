/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:59:15 by grusso            #+#    #+#             */
/*   Updated: 2022/03/26 18:47:24 by grusso           ###   ########.fr       */
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

		void	checkColor(Node<K, V> node) {
			if (node == NULL)
				return ;
			if (!node.black && !node.parent.black)
				correctTree(node.parent);
			checkColor(node.parent);
		}

		void	correctTree(Node<K, V> node) {
			if (node.parent.isLeftChild) { // aunt is node.parent.parent.right
				if (node.parent.parent.right == NULL || node.parent.parent.right.black)
					return (rotate(node));
				if (node.parent.parent.right != NULL)
					node.parent.parent.right.black = true;
				node.parent.parent.black = false;
				node.parent.black = true;
			}
			else { // aunt is node.parent.parent.left
				if (node.parent.parent.left == NULL || node.parent.parent.left.black)
					return (rotate(node));
				if (node.parent.parent.left != NULL)
					node.parent.parent.left.black = true;
				node.parent.parent.black = false;
				node.parent.black = true;
			}
		}

		void	rotate(Node<K, V> node) {
			if (node.isLeftChild) {
				if (node.parent.isLeftChild) {
					rightRotate(node.parent.parent);
					node.black = false;
					node.parent.black = true;
					if (node.parent.right != NULL)
						node.parent.right.black = false;
					return ;
				}
				rightLeftRotate(node.parent.parent);
				node.black = true;
				node.right.black = false;
				node.left.black = false;
			}
			else {
				if (!node.parent.isLeftChild) {
					leftRotate(node.parent.parent);
					node.black = false;
					node.parent.black = true;
					if (node.parent.left != NULL)
						node.parent.left.black = false;
					return ;
				}
				leftRightRotate(node.parent.parent);
				node.black = true;
				node.right.black = false;
				node.left.black = false;
			}
		}

		void	leftRotate(Node<K, V> node) {
			Node<K, V> tmp = node.right;
			node.right = tmp.left;
			if (node.right != NULL) {
				node.right.parent = node;
				node.right.isLeftChild = false;
			}
			if (node.parent == NULL) { // we are the root
				root = tmp;
				tmp.parent = NULL;
			}
			else {
				tmp.parent = node.parent;
				if (node.isLeftChild) {
					tmp.isLeftChild = true;
					tmp.parent.left = tmp;
				}
				else {
					tmp.isLeftChild = false;
					tmp.parent.right = tmp;
				}
			}
			tmp.left = node;
			node.isLeftChild = true;
			node.parent = tmp;
		}

		void	rightRotate(Node<K, V> node) {
			Node<K, V> tmp = node.right;
			node.right = tmp.left;
			if (node.right != NULL) {
				node.right.parent = node;
				node.right.isLeftChild = false;
			}
			if (node.parent == NULL) { // we are the root
				root = tmp;
				tmp.parent = NULL;
			}
			else {
				tmp.parent = node.parent;
				if (node.isLeftChild) {
					tmp.isLeftChild = true;
					tmp.parent.left = tmp;
				}
				else {
					tmp.isLeftChild = false;
					tmp.parent.right = tmp;
				}
			}
			tmp.left = node;
			node.isLeftChild = true;
			node.parent = tmp;
		}

		void	leftRightRotate(Node<K, V> node) {
			leftRotate(node.left);
			rightRotate(node);
		}

		void	rightLeftRotate(Node<K, V> node) {
			rightRotate(node.right);
			leftRotate(node);
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
