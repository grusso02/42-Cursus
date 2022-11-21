/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:15:29 by grusso            #+#    #+#             */
/*   Updated: 2022/11/21 10:48:22 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <iomanip>
#include "../utils/RBtree.hpp"
#include "../utils/RBtree_iterators.hpp"
#include "../utils/RBtree_utils.hpp"
#include "../utils/utils.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
        	typedef Key                                      				key_type;
        	typedef T                                        				mapped_type;
        	typedef pair<const key_type, mapped_type>        				value_type;
        	typedef Compare                                  				key_compare;
        	typedef Allocator                                				allocator_type;
        	typedef typename allocator_type::reference       				reference;
        	typedef typename allocator_type::const_reference 				const_reference;
        	typedef typename allocator_type::pointer         				pointer;
        	typedef typename allocator_type::const_pointer   				const_pointer;
        	typedef typename allocator_type::size_type       				size_type;
        	typedef typename allocator_type::difference_type 				difference_type;

     	class value_compare : public std::binary_function<value_type, value_type, bool>
     	{
     		friend class map<Key, T, key_compare, Allocator>;
     	 	protected:
     			key_compare			comp;

     		value_compare(key_compare __c) : comp(__c) {}

    		public:
     		bool operator()(const value_type& __x, const value_type& __y) const
     		{
				return comp(__x.first, __y.first);
			}
		};
		
		public:
			
			typedef ft::tree<value_type, key_compare, allocator_type>			_tree; //--> definiton of TREE

        	typedef typename ft::map_iterator<_tree>							iterator;
			typedef typename ft::const_map_iterator<_tree>						const_iterator;
			typedef typename ft::map_reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::const_map_reverse_iterator<const_iterator>		const_reverse_iterator;

        private:
		
			allocator_type		_alloc;
        	key_compare			compare;
			_tree				tree;

		public:
		
		//----------------------------------------CONSTRUCTORS , DESTRUCTOR--------------------------------------------------------------------------//
		
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :  _alloc(alloc), compare(comp) {};

			template <class InputIterator>
  			map (InputIterator first, InputIterator last,
			  	const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) : _alloc(alloc), compare(comp) {

					while(first != last)
					{
						insert(*first);
						first++;
					}	
				}
			map (const map& x) : _alloc(x._alloc), compare(x.compare) {

				const_iterator tmp = x.begin();
				while(tmp != x.end())
				{
					insert(*tmp);
					tmp++;
				}
			}
			
			~map(){};
		
		//---------------------------------------OPERATORS OVERLOADING--------------------------------------//

			map& operator= (const map& x){

				this->_alloc = x._alloc;
				this->compare = x.compare;
				tree.ft_tree_clear();
				const_iterator tmp = x.begin();
				while(tmp != x.end())
				{
					insert(*tmp);
					tmp++;
				}
				return *this;
			}
		
		//----------------------------------------ITERATORS-------------------------------------------------//
		
		iterator end() { return iterator(tree.get_end()) ;}
		iterator begin() { return iterator(tree.get_end()->right); }
		const_iterator end() const { return const_iterator(tree.get_end()); }
		const_iterator begin() const { return const_iterator(tree.get_end()->right); }
		size_type size() const { return this->tree.get_size(); }
		
		reverse_iterator rbegin() { return reverse_iterator(tree.get_end()->left); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(tree.get_end()->left); }
		reverse_iterator rend() { return reverse_iterator (tree.get_end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator (tree.get_end()); }
		
		//------------------------------------------METHODS-------------------------------------------------//
		
		size_type erase (const key_type& k)
		{
			iterator it = find(k);
			if (it == end())
				return 0;
			tree.erase(it.base());
			return 1;
		}

		void erase (iterator position)
		{
			tree.erase(position.base());
		}

		void erase (iterator first, iterator last)
		{
			tree.erase(first.base(), last.base());
		}
		
		value_compare value_comp() const
		{
			return value_compare(this->compare);
		}
		
		key_compare key_comp() const
		{
			return key_compare();
		}

		void swap (map& x)
		{
			std::swap(this->_alloc, x._alloc);
			std::swap(this->compare, x.compare);
			tree.swap(x.tree);
		}

		pair<iterator, bool> insert (const value_type& val)
		{
			pair<typename _tree::node_pointer, bool> inserted = tree.tree_insert(val);
			iterator iter(inserted.first);
			return (ft::make_pair(iter, inserted.second));
		}
		
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			iterator ret(tree.tree_insert(val).first);
			return ret;
		}
		
		template <class InputIterator>
  		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
			{
				value_type val = ft::make_pair(first->first, first->second);
				tree.tree_insert(val);
			}
		}

		void clear(){

			tree.ft_tree_clear();
		}

		iterator find(const key_type& k)
		{
			return iterator(tree.find(k));
		}

		const_iterator find(const key_type& k) const
		{
			return const_iterator(tree.find(k));
		}

		size_type count(const key_type& k) const
		{
			return tree.count(k);
		}

		bool empty() const
		{
			return tree.empty();
		}

		iterator lower_bound(const key_type& k)
		{
			return iterator(tree.lower_bound(k));
		}

		const_iterator lower_bound (const key_type& k) const
		{
			return const_iterator(tree.lower_bound(k));
		}

		iterator	upper_bound(const key_type& k)
		{
			return iterator(tree.upper_bound(k));
		}

		const_iterator upper_bound (const key_type& k) const
		{
			return const_iterator(tree.upper_bound(k));
		}

		pair<iterator,iterator>	equal_range (const key_type& k)
		{
			return tree.equal_range(k);
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return tree.equal_range(k);
		}
		
		size_type max_size() const
		{
			return(tree.tree_max_size());
		}

		mapped_type& operator[] (const key_type& k)
		{
			return((insert(ft::make_pair(k,mapped_type())).first)->second);
		}

    };
	//----------------------------------------RELATIONAL OPERATORS-------------------------------------------------//

	template <class Key, class T, class Compare, class Allocator>
	bool operator< (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
    	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator==(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
   		return x.size() == y.size() && !(x<y) && !(y<x);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
   		return !(x == y);
	}		

	template <class Key, class T, class Compare, class Allocator>
	bool operator> (const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
		return (y < x);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
		return !(x < y);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const map<Key, T, Compare, Allocator>& x, const map<Key, T, Compare, Allocator>& y)
	{
		return !(y < x);
	}
} // namespace ft
