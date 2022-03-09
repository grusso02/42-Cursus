/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:21:39 by gabriele          #+#    #+#             */
/*   Updated: 2022/03/06 12:20:49 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <algorithm>
# include <memory>
# include <functional>
# include <limits>
# include <string>
# include <utility>
# include <stdexcept>
# include <cstring>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
		public:
			//Member Types
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			//Constructors
			explicit vector(const allocator_type& alloc = allocator_type())
			: 
					_size(0),
					_capacity(0),
					_begin(nullptr),
					_alloc(alloc) 
			{}
			
			explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
			:
					_size(0),
					_capacity(0),
					_begin(nullptr),
					_alloc(alloc)
			{
				if (n > 0)
				{
					_size = n;
					_capacity = n * 2;
					_begin = _alloc.allocate(_capacity);
					for (size_t i = 0; i < n; i++)
						_begin[i] = val;
				}
			}

/* 			explicit vector (const vector& x) : _size(0), _capacity(0), _begin(nullptr), _alloc(x._alloc)
			{
				_size = x._size;
				_capacity = x._capacity;
				_begin = _alloc.allocate(_capacity);
				assign(x._begin, (x._begin + x._size));
			} */

			vector (const vector& x) : _size(0), _capacity(0), _begin(nullptr), _alloc(x._alloc) 
			{
				_capacity = x._capacity;
				_size = x._size;
				_begin = _alloc.allocate(_capacity);
				assign(x._begin, (x._begin + x._size));
			}

			~vector()
			{
				if (_begin != nullptr || _capacity != 0)
				{
					_alloc.deallocate(_begin, _capacity);
				}
			}

		private:
			size_t			_size;
			size_t			_capacity;
			pointer			_begin;
			allocator_type	_alloc;
	};

} // namespace ft

#endif