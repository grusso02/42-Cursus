/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:01:14 by gabriele          #+#    #+#             */
/*   Updated: 2022/03/15 15:42:24 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

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

} // namespace ft


#endif