/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:26:53 by grusso            #+#    #+#             */
/*   Updated: 2022/04/02 17:05:57 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			/********************** Member Types **********************/
			typedef Container                                container_type;
			typedef typename container_type::value_type      value_type;
			typedef typename container_type::reference       reference;
			typedef typename container_type::const_reference const_reference;
			typedef typename container_type::size_type       size_type;

		protected:
			container_type _c;

		public:
			/********************** Constructors **********************/
			stack() : _c() {}
			explicit stack(const container_type& c) : _c(c) {}
			~stack() {}

			stack(const stack& q) : _c(q._c) {}

			stack& operator=(const stack& q) { _c = q._c; return *this; }

			/********************** Member Functions **********************/
			bool			empty() const { return _c.empty(); }
			size_type		size() const { return _c.size(); }
			reference		top() { return _c.back(); }
			const_reference	top() const { return _c.back(); }
			void			push(const value_type& v) { _c.push_back(v); }
			void			pop() { _c.pop_back(); }

			template <class T1, class _C1>
			friend bool operator==(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);

			template <class T1, class _C1>
			friend bool operator<(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
	};

	/********************** Overload Relational Operators **********************/
	template <class _Tp, class _Container>
	bool operator==(const stack<_Tp, _Container>& __x, const stack<_Tp, _Container>& __y)
	{
    	return __x._c == __y._c;
	}

	template <class _Tp, class _Container>
	bool operator<(const stack<_Tp, _Container>& __x, const stack<_Tp, _Container>& __y)
	{
    	return __x._c < __y._c;
	}

	template <class _Tp, class _Container>
	bool operator!=(const stack<_Tp, _Container>& __x, const stack<_Tp, _Container>& __y)
	{
		return !(__x == __y);
	}

	template <class _Tp, class _Container>
	bool operator>(const stack<_Tp, _Container>& __x, const stack<_Tp, _Container>& __y)
	{
		return __y < __x;
	}

	template <class _Tp, class _Container>
	bool operator>=(const stack<_Tp, _Container>& __x, const stack<_Tp, _Container>& __y)
	{
		return !(__x < __y);
	}

	template <class _Tp, class _Container>
	bool operator<=(const stack<_Tp, _Container>& __x, const stack<_Tp, _Container>& __y)
	{
		return !(__y < __x);
	}

} // namespace ft
