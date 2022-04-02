/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriele <gabriele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:01:14 by gabriele          #+#    #+#             */
/*   Updated: 2022/04/02 17:05:49 by gabriele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstddef>

namespace ft
{
	/********************** enable_if **********************/
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	/********************** is_integral **********************/
    template <bool value_type, typename T>
	struct integral_constant
	{
        typedef T type;
        static const bool value = value_type;
    };

	//Template Spacialization
    template <typename> struct is_integral : public integral_constant<false, bool> {}; //Base template
	template <>			struct is_integral<bool> : public integral_constant<true, bool> {}; //bool specialization
	template <>			struct is_integral<char> : public integral_constant<true, char> {};
	template <>			struct is_integral<char16_t> : public integral_constant<true, char16_t> {};
	template <>			struct is_integral<char32_t> : public integral_constant<true, char32_t> {};
	template <>			struct is_integral<wchar_t> : public integral_constant<true, wchar_t> {};
	template <>			struct is_integral<signed char> : public integral_constant<true, signed char> {};
	template <>			struct is_integral<unsigned char> : public integral_constant<true, unsigned char> {};
	template <>			struct is_integral<short int> : public integral_constant<true, short int> {};
	template <>			struct is_integral<int> : public integral_constant<true, int> {};
	template <>			struct is_integral<long int> : public integral_constant<true, long int> {};
	template <>			struct is_integral<long long int> : public integral_constant<true, long long int> {};
	template <>			struct is_integral<unsigned short int> : public integral_constant<true, unsigned short int> {};
	template <>			struct is_integral<unsigned int> : public integral_constant<true, unsigned int> {};
	template <>			struct is_integral<unsigned long int> : public integral_constant<true, unsigned long int> {};
	template <>			struct is_integral<unsigned long long int> : public integral_constant<true, unsigned long long int> {};

	/********************** lexicographical_compare **********************/
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	/********************** pair **********************/
	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		//Constructor
		pair() : first(), second() {}
		pair(T1 const& __t1, T2 const& __t2) : first(__t1), second(__t2) {}

		//operator=
		pair& operator=(pair const& __p)
		{
			first = __p.first;
			second = __p.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs<lhs);
	}

	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs<rhs);
	}

	//make_pair
	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x, y));
	}

} // namespace ft
