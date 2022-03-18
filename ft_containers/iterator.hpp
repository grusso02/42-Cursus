/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:04:25 by grusso            #+#    #+#             */
/*   Updated: 2022/03/18 11:28:11 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <cstddef>
#include <iostream>

namespace ft
{
	/********************** Iterator Traits **********************/
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
	};

	template<class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};

	/********************** Iterator **********************/
	template <class Iterator>
	class base_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
	{
	private:
		Iterator current;
	public:
		typedef Iterator                                            iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::reference       reference;
		typedef typename iterator_traits<Iterator>::pointer         pointer;

		base_iterator() : current(nullptr) {}
		explicit base_iterator(Iterator x) : current(x) {}
		template <class U> base_iterator(const base_iterator<U>& u) : current(u.base()) {}
		template <class U> base_iterator& operator=(const base_iterator<U>& u) { current = u.base(); return *this; }
		Iterator base() const { return current; }
		reference operator*() const { return static_cast<reference>(*current); }
		pointer   operator->() const { return current; }
		base_iterator& operator++() {  ++current; return *this; }
		base_iterator  operator++(int) { base_iterator tmp(*this); ++current; return tmp; }
		base_iterator& operator--() { --current; return *this; }
		base_iterator  operator--(int) { base_iterator tmp(*this); --current; return tmp; }
		base_iterator  operator+ (difference_type n) const { return base_iterator(current + n); }
		base_iterator& operator+=(difference_type n) { current += n; return *this; }
		base_iterator  operator- (difference_type n) const { return base_iterator(current - n);}
		base_iterator& operator-=(difference_type n) { current -= n; return *this; }
		reference operator[](difference_type n) const { return static_cast<reference>(current[n]); }
	};

	template <class Iterator1, class Iterator2>
  	bool operator== (const base_iterator<Iterator1>& x, const base_iterator<Iterator2>& y)
	{
		return x.base() == y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!= (const base_iterator<Iterator1>& x, const base_iterator<Iterator2>& y)
	{
		return x.base() != y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<  (const base_iterator<Iterator1>& x, const base_iterator<Iterator2>& y)
	{
		return x.base() < y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<= (const base_iterator<Iterator1>& x, const base_iterator<Iterator2>& y)
	{
		return x.base() <= y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>  (const base_iterator<Iterator1>& x, const base_iterator<Iterator2>& y)
	{
		return x.base() > y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>= (const base_iterator<Iterator1>& x, const base_iterator<Iterator2>& y)
	{
		return x.base() >= y.base();
	}

	template <class Iterator>
	base_iterator<Iterator> operator+(typename base_iterator<Iterator>::difference_type n,const base_iterator<Iterator>& rev_it)
	{
		return base_iterator<Iterator>(rev_it.base() + n);
	}

	template <class Iterator1, class Iterator2> 
	typename base_iterator<Iterator1>::difference_type operator-(const base_iterator<Iterator1>& __x, const base_iterator<Iterator2>& __y)
	{
		return __x.base() - __y.base();
	}

	/********************** Reverse Iterator **********************/
	template <class Iterator>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
						typename iterator_traits<Iterator>::value_type,
						typename iterator_traits<Iterator>::difference_type,
						typename iterator_traits<Iterator>::pointer,
						typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator current;
		public:
			typedef Iterator                                            iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::reference       reference;
			typedef typename iterator_traits<Iterator>::pointer         pointer;

			reverse_iterator() : current() {}
			explicit reverse_iterator(Iterator x) : current(x) {}
			template <class U> reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {}
			template <class U> reverse_iterator& operator=(const reverse_iterator<U>& u) { current = u.base(); return *this; }
			Iterator base() const { return current; }
			reference operator*() const { Iterator tmp = current; return *--tmp; }
			pointer   operator->() const { return &(operator*()); }
			reverse_iterator& operator++() { --current; return *this; }
			reverse_iterator  operator++(int) { reverse_iterator tmp(*this); --current; return tmp; }
			reverse_iterator& operator--() { ++current; return *this; }
			reverse_iterator  operator--(int) { reverse_iterator tmp(*this); ++current; return tmp; }
			reverse_iterator  operator+ (difference_type n) const { return reverse_iterator(current - n); }
			reverse_iterator& operator+=(difference_type n) { current -= n; return *this; }
			reverse_iterator  operator- (difference_type n) const { return reverse_iterator(current + n); }
			reverse_iterator& operator-=(difference_type n) { current += n; return *this; }
			reference         operator[](difference_type n) const { return *(*this + n); }
	};
	
	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() == y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() > y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() != y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() < y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() <= y.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return x.base() >= y.base();
	}

	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return y.base() - x.base();
	}

	template <class _Iter>
	reverse_iterator<_Iter> operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter>& __x)
	{
		return reverse_iterator<_Iter>(__x.base() - __n);
	}

	/********************** Map Iterator **********************/
	template <class _TreeIterator>
	class __map_iterator
	{
		typedef typename _TreeIterator::_NodeTypes					_NodeTypes;
    	typedef typename _TreeIterator::__pointer_traits			__pointer_traits;

    	_TreeIterator __i_;

		public:
			typedef bidirectional_iterator_tag						iterator_category;
			typedef typename _NodeTypes::__map_value_type			value_type;
			typedef typename _TreeIterator::difference_type			difference_type;
			typedef value_type&										reference;
			typedef typename _NodeTypes::__map_value_type_pointer	pointer;
		
		__map_iterator() {}
		__map_iterator(_TreeIterator __i) : __i_(__i) {}

		reference operator*() const { return __i_->__get_value(); }
		pointer operator->() const { return pointer_traits<pointer>::pointer_to(__i_->__get_value()); }
		__map_iterator& operator++() { ++__i_; return *this; }
		__map_iterator operator++(int)
		{
			__map_iterator __t(*this);
			++(*this);
			return __t;
		}

		__map_iterator& operator--() {--__i_; return *this;}
		__map_iterator operator--(int)
		{
			__map_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator==(const __map_iterator& __x, const __map_iterator& __y) { return __x.__i_ == __y.__i_; }
		friend bool operator!=(const __map_iterator& __x, const __map_iterator& __y) { return __x.__i_ != __y.__i_; }

		template <class, class, class, class> friend class map;
		template <class, class, class, class> friend class multimap;
		template <class> friend class __map_const_iterator;
	}

	/********************** Map Const Iterator **********************/
	template <class _TreeIterator>
	class __map_const_iterator
	{
		typedef typename _TreeIterator::_NodeTypes                   _NodeTypes;
		typedef typename _TreeIterator::__pointer_traits             __pointer_traits;

		_TreeIterator __i_;

		public:
			typedef bidirectional_iterator_tag                           iterator_category;
			typedef typename _NodeTypes::__map_value_type                value_type;
			typedef typename _TreeIterator::difference_type              difference_type;
			typedef const value_type&                                    reference;
			typedef typename _NodeTypes::__const_map_value_type_pointer  pointer;

		__map_const_iterator() {}	
		__map_const_iterator(_TreeIterator __i) : __i_(__i) {}
		__map_const_iterator(__map_iterator<typename _TreeIterator::__non_const_iterator> __i) : __i_(__i.__i_) {}

		reference operator*() const {return __i_->__get_value();}
		pointer operator->() const {return pointer_traits<pointer>::pointer_to(__i_->__get_value());}
		__map_const_iterator& operator++() {++__i_; return *this;}
		__map_const_iterator operator++(int)
		{
			__map_const_iterator __t(*this);
			++(*this);
			return __t;
		}
		__map_const_iterator& operator--() {--__i_; return *this;}
		__map_const_iterator operator--(int)
		{
			__map_const_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator==(const __map_const_iterator& __x, const __map_const_iterator& __y) { return __x.__i_ == __y.__i_; }
		friend bool operator!=(const __map_const_iterator& __x, const __map_const_iterator& __y) { return __x.__i_ != __y.__i_; }

		template <class, class, class, class> friend class map;
		template <class, class, class, class> friend class multimap;
		template <class, class, class> friend class __tree_const_iterator;
	};

} // namespace ft

#endif