/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:21:39 by gabriele          #+#    #+#             */
/*   Up	ed: 2022/03/14 14:33:39 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>
#include <limits>
#include <utility>
#include <stdexcept>
#include <cstring>
#include "../utils/iterator.hpp"
#include "../utils/utils.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> > 
	class vector
	{
		public:
			/********************** Member Types **********************/
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

			/********************** Constructors **********************/
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
    		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
				:
					_size(0),
					_capacity(0),
					_begin(nullptr),
					_alloc(alloc)
			{
				assign(first, last);
			}

			vector(const vector& x)
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

			~vector()
			{
				if (_begin != nullptr || _capacity != 0)
				{
					_alloc.deallocate(_begin, _capacity);
				}
			}

			vector& operator=(const vector& x)
			{
				_size = x._size;
				_capacity = x._capacity;
				_alloc = x._alloc;
				assign(x._begin, (x._begin + _size));
				return(*this);
			}

			/********************** Iterator **********************/
			iterator				begin() { return iterator(_begin); }
			const_iterator			begin() const { return const_iterator(_begin); }
			iterator				end() { return iterator(_begin + _size); }
			const_iterator			end() const { return const_iterator(_begin + _size); }
			reverse_iterator		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator	rbegin() const { return const_reverse_iterator(end()); }
			reverse_iterator		rend() { return reverse_iterator((begin())); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }

			/********************** Capacity **********************/
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
			bool		empty() const { return(_size == 0); }

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

			/********************** Element access **********************/
			reference operator[](size_type pos) { return(this->_begin[pos]); }
			const_reference operator[](size_type pos) const { return(this->_begin[pos]); }
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

			/********************** Modifiers **********************/
			template <class InputIterator>
			void		assign (InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
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

			void		assign(size_type n, const value_type& val)
			{
				if (n > _capacity)
					reserve(n * 2);
				_size = n;
				for (size_t i = 0; i < _size; i++)
					_begin[i] = val;
			}

			void		push_back(const value_type& val)
			{
/* 				if ((_size + 1) >= _capacity)
					reserve((_size + 1) * 2);
				_size++;
				_alloc.construct((_begin + _size - 1), val);
				_begin[_size - 1] = val; */
				if (this->_size + 1 > this->_capacity)
                	reserve(this->_capacity < 2 ? 2 : this->_capacity * 2);
            	this->_alloc.construct(this->_begin + this->_size++, val);
			}

			void		pop_back() { _size--; }

			iterator	insert(iterator position, const value_type& val)
			{
				size_t pos = 0;
				for (iterator it = begin(); it != position; it++)
					pos++;
				if (_size+1 > _capacity)
					reserve((_size + 1)*2);
				_size++;
				size_t iter = _size;
				while (iter != pos && (iter - 1) != pos)
				{
					_begin[iter - 1] = _begin[iter - 2];
					iter--;
				}
				_begin[pos] = val;
				size_t index = 0;
				iterator i = begin();
				for (; index != pos; i++)
					index++;
				return (i);
			}
			
			void		insert(iterator position, size_type n, const value_type& val)
			{
				size_t pos = 0;
				for (iterator it = begin(); it != position; ++it)
					pos++;
				if (_size + n > _capacity)
					reserve((_size + n) *2);
				_size += n;
				size_t index = _size;
				while (index > pos && (index - n) > pos)
				{
					_begin[index - 1] = _begin[index - n - 1];
					index--;
				}
				size_t j = 0;
				while (j < n)
				{
					_begin[pos] = val;
					pos++;
					j++;
				}
			}

			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last,
								typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				size_t range = 0;
				for (InputIterator i = first; i != last; ++i)
					range++;
				size_t pos = 0;
				for (iterator it = begin(); it != position; ++it)
					pos++;
				if (_size + range > _capacity)
					reserve((_size + range)*2);
				_size += range;
				size_t index = _size;
				while (index > pos && (index - range) > pos)
				{
					_begin[index - 1] = _begin[index - range - 1];
					index--;
				}
				for(; first != last; first++, pos++)
					_begin[pos] = *first;
			}

			iterator	erase(iterator position)
			{
				_size--;
				iterator i = (iterator)_begin;
				size_t pos = 0;
				while (i < position)
				{
					pos++;
					i++;
				}
				while (pos != _size)
				{
					_begin[pos] = _begin[pos + 1];
					pos++;
				}
				return (position);
			}

			iterator	erase(iterator first, iterator last)
			{
				size_t range = 0;
				iterator tmp;
				iterator tmp2 = (iterator)_begin;
				size_t pos = 0;
				tmp = first;
				while (tmp2 != first)
				{
					tmp2++;
					pos++;
				}
				while (tmp != last)
				{
					tmp++;
					range++;
				}
				_size -= range;
				while (pos < _size)
				{
					_begin[pos] = _begin[pos + range];
					pos++;
				}
				return (first);
			}

			void		swap(vector& x)
			{
				std::swap(this->_begin, x._begin);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_alloc, x._alloc);
			}

			void		clear() { this->_size = 0; }

			/********************** Allocator **********************/
			allocator_type get_allocator() const { return this->_alloc; }
	
		private:
			size_t			_size;
			size_t			_capacity;
			pointer			_begin;
			allocator_type	_alloc;
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y) 
	{
		return (!(x > y) && !(x < y));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return (!(x == y));
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
		
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& x, const vector<T,Alloc>& y) 
	{
		return (ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));	
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return (!(x > y));
	}
		
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return (!(x < y));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

} // namespace ft
