/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:26:00 by grusso            #+#    #+#             */
/*   Updated: 2022/03/18 10:48:51 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include "utils.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< pair<const Key, T> > >
	class map
	{
		public:
			/********************** Member Types **********************/
			typedef _Key									key_type;
			typedef _Tp										mapped_type;
			typedef pair<const key_type, mapped_type>		value_type;
			typedef _Compare								key_compare;
			typedef _Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;

		private:
			typedef __map_value_compare<key_type, __value_type, key_compare>	__vc;
			typedef __tree<__value_type, __vc, __allocator_type>				__base;

		public:
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef __map_iterator<typename __base::iterator>		iterator;
			typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
			typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
			typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;

			__base __tree_;

			/********************** Member Types **********************/
			map()
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			map (const map& x);
	};

} // namespace ft

#endif