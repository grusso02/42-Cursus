/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:40 by grusso            #+#    #+#             */
/*   Updated: 2022/11/19 16:55:27 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../utils/RBtree_iterators.hpp"
#include "../utils/RBtree_utils.hpp"
#include "../utils/utils.hpp"
#include "../src/vector.hpp"

namespace ft
{
	template<class value, class compare = std::less<typename value::first_type>, class alloc = std::allocator<value> > // --> value = pair (key, mapped value)
    class tree
    {
        public:
			typedef value                                     	value_type; //--> PAIR
			typedef	compare										value_compare; //--> COMPARE TRA KEY -->FIRST ARG, NO PAIR
        	typedef alloc    	     							allocator_type;
			typedef typename std::allocator<Node<value> >		node_allocator; 
			
        	typedef typename node_allocator::reference			node_reference;
        	typedef typename node_allocator::const_reference	const_node_reference;
        	typedef typename node_allocator::pointer			node_pointer;
			typedef typename node_allocator::const_pointer		const_node_pointer;
			
        	typedef size_t           							size_type;
        	typedef ptrdiff_t        							difference_type;
        	typedef typename value::first_type                  first_type;
        	typedef typename value::second_type                 second_type;
			typedef typename vector<node_pointer>::iterator		vec_iterator;
			typedef typename vector<value_type>::iterator		pairvec_iterator;

        private:
        	node_allocator										_alloc;
		    node_pointer										root;
			node_pointer										end;
			value_compare										comp;
			size_type											size;
			vector<node_pointer>								node_vec;

		public:
		//----------------------------------------CONSTRUCTOR, DESTRUCTOR-------------------------------------------------//

			tree(const value_compare& _compare = value_compare(),  const node_allocator& _a = node_allocator()) : 
				_alloc(_a),
				root(NULL),
				comp(_compare),
				size(0)	{
					
					end = _alloc.allocate(1);
					_alloc.construct(end, Node<value_type>());
					end->right = end;
					end->left = end;
				};
			
			~tree(){
				
				for(size_t i = 0; i < this->size; i++)
				{
					_alloc.destroy((node_vec[i]));
					_alloc.deallocate(node_vec[i], 1);
				}
				_alloc.deallocate(end, 1);
				
			}
			
			node_pointer	get_root() const { return this->root ;}
			node_pointer	get_begin() const {return this->end->right;};
			node_pointer	get_end() const { return this->end ;}
			size_type		get_size() const { return this->size; }
			value_compare  	key_comp() const  { return this->comp; }

			void	ft_erase_vec()
			{
				vector<value_type>	new_node_vec;
				vec_iterator v_beg = node_vec.begin();
				while(v_beg != node_vec.end())
				{
					new_node_vec.push_back(ft::make_pair((*v_beg)->_pair.first, (*v_beg)->_pair.second));
					v_beg++;
				}
				ft_tree_clear();
				pairvec_iterator nv_beg = new_node_vec.begin();
				while(nv_beg != new_node_vec.end())
				{
					tree_insert((*nv_beg));
					nv_beg++;
				}
			}

			void erase (node_pointer node)
			{
				vec_iterator v_beg = node_vec.begin();
				while(v_beg != node_vec.end())
				{
					if(*v_beg == node)
					{
						_alloc.destroy((*v_beg));
						_alloc.deallocate(*v_beg, 1);
						node_vec.erase(v_beg);
						size--;
						ft_erase_vec();
						return;
					}
					v_beg++;
				}	
			}

			void erase (node_pointer first, node_pointer second )
			{
				vector<node_pointer>	new_node_vec;
				size_t len = 0;
				while(first != second)
				{
					new_node_vec.push_back(first);
					first = next_node(first);
					len++;
				}
				vec_iterator st = new_node_vec.begin();
				vec_iterator v_beg = node_vec.begin();
				while(len)
				{
					if(*v_beg == *st)
					{
						st++;
						_alloc.destroy((*v_beg));
						_alloc.deallocate(*v_beg, 1);
						node_vec.erase(v_beg);
						size--;
						len--;
					}
					if(v_beg == node_vec.end())
						v_beg = node_vec.begin();
					else
						v_beg++;
					}
			
				ft_erase_vec();	
			}
		
			void ft_tree_clear()
			{
				vec_iterator v_beg = node_vec.begin();
				vec_iterator v_end = node_vec.end();
				for(size_t i = 0; i < this->size; i++)
				{
					_alloc.destroy((node_vec[i]));
					_alloc.deallocate(node_vec[i], 1);
				}
				node_vec.erase(v_beg, v_end);
				this->size = 0;
				root = NULL;
				end->right = end;
				end->left = end;
				end->parent = NULL;
				
			}

			void swap(tree& x)
			{
				std::swap(this->_alloc, x._alloc);
				std::swap(root, x.root);
				std::swap(end, x.end);
				std::swap(comp, x.comp);
				std::swap(size, x.size);
				std::swap(node_vec, x.node_vec);
			}

			pair<node_pointer, bool> tree_insert (const value_type& val)
			{
				node_pointer	tmp;
				if (root == NULL)
				{
					this->root = _alloc.allocate(1);
					node_vec.push_back(root);
					_alloc.construct(root, val);
					this->end->left = root;
					this->end->right = root;
					this->root->parent = end;
					this->root->right = end;
					this->root->left = end;
					tmp = root;
					this->size++;
				}
				else if (this->comp(val.first, end->right->_pair.first) || 
						!(this->comp(val.first, end->left->_pair.first)) || 
						(val.first == end->right->_pair.first))
				{
					// std::cout << "entrato con:" << val.first << std::endl;
					if (val.first == end->right->_pair.first)
						return (ft::make_pair(end->right, false));
					else if (val.first == end->left->_pair.first)
						return (ft::make_pair(end->left, false));
					tmp = _alloc.allocate(1);
					node_vec.push_back(tmp);
					_alloc.construct(tmp, val);
					if (this->comp(val.first, end->right->_pair.first))
					{
						end->right->left = tmp;
						tmp->parent = end->right;
						end->right = tmp;
						tmp->left = end;
					}
					else if (!(this->comp(val.first, end->left->_pair.first)))
					{
						end->left->right = tmp;
						tmp->parent = end->left;
						end->left = tmp;
						tmp->right = end;
					}
					this->size++;
				}
				else
				{
					node_pointer	ptr = this->root;
					while (1)
					{
						if (ptr->left && this->comp(val.first, ptr->_pair.first))
							ptr = ptr->left;
						else if (ptr->right && !this->comp(val.first, ptr->_pair.first))
							ptr = ptr->right;
						if (val.first == ptr->_pair.first)
							return (ft::make_pair(ptr, false));
						if (!ptr->left && this->comp(val.first, ptr->_pair.first))
						{
							tmp = _alloc.allocate(1);
							_alloc.construct(tmp, val);
							tmp->parent = ptr;
							ptr->left  = tmp;
							break ;
						}
						else if (!this->comp(val.first, ptr->_pair.first) && !ptr->right)
						{
							tmp = _alloc.allocate(1);
							_alloc.construct(tmp, val);
							tmp->parent = ptr;
							ptr->right  = tmp;
							break ;
						}
					}
						node_vec.push_back(tmp);
						this->size++;
				}
				return (ft::make_pair(tmp, true));
			}

			node_pointer	find(const first_type& k) const
			{
				if (k == end->right->_pair.first) //--> = piu piccolo
					return node_pointer(end->right);
				else if (k == end->left->_pair.first) // --> = piu grande
					return node_pointer(end->left);
				node_pointer tmp = this->root;
				if (k == tmp->_pair.first) // --> = root
					return tmp;
				if (this->comp(k, tmp->_pair.first)) //--> se minore
				{
					while (tmp != end->right)
					{
						if (k == tmp->_pair.first)
							return tmp;
						tmp = prev_node(tmp);
					}
				}
				else
				{
					while (tmp != end->left)
					{
						if (k == tmp->_pair.first)
							return tmp;
						tmp = next_node(tmp);
					}
				}
				return node_pointer(end);
			}

			size_type count(const first_type& k) const
			{
				node_pointer tmp = find(k);
				if (tmp != end)
					return 1;
				return 0;
			}

			bool empty() const
			{
				return (this->size == 0? 1 : 0);
			}

			size_type tree_max_size() const{

				return this->_alloc.max_size();
			}

			node_pointer	lower_bound(const first_type& k) const
			{
				for (node_pointer tmp = get_begin(); tmp != get_end(); tmp = next_node(tmp))
				{
					if (this->comp(k, tmp->_pair.first) || k == tmp->_pair.first)
						return node_pointer(tmp);
				}
				return node_pointer(get_end());
			}

			node_pointer	upper_bound(const first_type& k) const
			{
				for (node_pointer tmp = get_begin(); tmp != get_end(); tmp = next_node(tmp))
					if (this->comp(k, tmp->_pair.first))
						return node_pointer(tmp);
				return node_pointer(get_end());
			}

			pair<node_pointer, node_pointer>	equal_range(const first_type& k) const
			{
				return pair<node_pointer , node_pointer>(lower_bound(k), upper_bound(k));
			}
    };
} // namespace ft
