/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:21:39 by gabriele          #+#    #+#             */
/*   Updated: 2022/03/11 18:55:25 by grusso           ###   ########.fr       */
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
# include "iterator.hpp"

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
			typedef ft::base_iterator<pointer>					iterator;
			typedef ft::base_iterator<const_pointer>			const_iterator;
			typedef ft::reverse_iterator<iterator>         		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			class out_of_range : public std::out_of_range
			{
				public:
					out_of_range(std::string msg) : std::out_of_range(msg) {};
			};

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

			template <class InputIterator>
    		vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type())
				:
					_size(0),
					_capacity(0),
					_begin(nullptr),
					_alloc(alloc)
			{
				assign(first, last);
			}

			explicit vector(const vector& x)
			:
					_size(0),
					_capacity(0),
					_begin(nullptr),
					_alloc(x._alloc)
			{
				_size = x._size;
				_capacity = x._capacity;
				_begin = _alloc.allocate(_capacity);
				assign(x._begin, (x._begin + x._size));
			}

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

			//Capacity
			size_t		size() const { return (_size); }
			size_type	max_size() const { return ( _alloc.max_size()); }

			void		resize(size_type n, value_type val = value_type())
			{
				if (n >= _size)
				{
					if (n > _capacity)
						reserve(n);
					if (!val)
						val = 0;
					for (size_t i = _size; i < n; i++)
						_begin[i] = val;
				}
				_size = n;
			}

			size_t		capacity() const { return (_capacity); }
			bool		empty( return (_size == 0); )

			void		reserve(size_type n)
			{
				if (n > _capacity && _begin != nullptr)
				{
					pointer tmp = NULL;
					tmp = _alloc.allocate(n);
					for (size_t i = 0; i < _size; i++)
							_alloc.construct((tmp + i), _begin[i]);
					_alloc.deallocate(_begin, _capacity);
					_begin = _alloc.allocate(n);
					for (size_t i = 0; i < _size; i++)
							_alloc.construct((_begin + i), tmp[i]);
					_capacity = n;
					_alloc.deallocate(tmp, n);
				}
				else if (_begin == nullptr)
				{
					_capacity = n;
					_begin = _alloc.allocate(_capacity);
				}
			}

			//Element access
			reference operator[](size_type pos) { this->_begin[pos]; }
			const_reference operator[](size_type pos) const { this->_begin[pos]; }
			reference at(size_type n)
			{
				if (n > _size)
					throw(out_of_range("vector"));
				return (_begin[n]);	
			}
			const_reference at(size_type n) const
			{
				if (n > _size)
					throw(out_of_range("vector"));
				return (_begin[n]);	
			}
			reference front() { return _begin[0]; }
			const_reference front() const { return _begin[0]; }
			reference back(){ return _begin[_size - 1]; }
			const_reference back() const { return _begin[_size - 1]; }

			//Modifiers
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				_size = 0;
				InputIterator tmp;
				tmp = first;
				while (tmp != last)
				{
					tmp++;
					_size++;
				}
				if (_begin != nullptr && _capacity != 0)
					this->_alloc.deallocate(this->_begin, this->_capacity);
				_capacity = _size * 2;
				_begin = _alloc.allocate(_capacity);
				for (size_t i = 0; first != last; first++, i++)
					_begin[i] = *first;
			}

			void assign(size_type n, const value_type& val)
			{
				if (n > _capacity)
					reserve(n * 2);
				_size = n;
				for (size_t i = 0; i < _size; i++)
					_begin[i] = val;
			}

			void push_back(const value_type& val)
			{
				if ((_size + 1) >= _capacity)
					reserve((_size + 1) * 2);
				_size++;
				_alloc.construct((_begin + _size - 1), val);
				_begin[_size - 1] = val;
			}

			void pop_back() { size--; }

		private:
			size_t			_size;
			size_t			_capacity;
			pointer			_begin;
			allocator_type	_alloc;
	};

} // namespace ft

#endif