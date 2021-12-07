#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array
{
	public:
		Array() : sz(0), arr(new T[0]) {};
		Array(unsigned int n) : sz(n), arr(new T[n]) {};
		Array(const Array& other)
		{
			sz = other.sz;
			arr = new T[other.sz];
			for (int i = 0; i < sz; i++)
				arr[i] = other.arr[i];
		}
		~Array() { delete[] arr; };

		Array&	operator=(const Array& other)
		{
			delete[] arr;
			sz = other.sz;
			arr = new T[other.sz];
			for (int i = 0; i < other.sz; i++)
				arr[i] = other.arr[i];
			return (*this);
		};

		T&	operator[](unsigned int i) const
		{
			if (i < 0 || i > sz - 1)
				throw Array::OverflowArray();
			else
				return (arr[i]);
		}

		unsigned int	size() const { return sz; };

	private:
		unsigned int	sz;
		T				*arr;

	public:
		class OverflowArray : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "Error: Bad access"; };
		};
};


# endif