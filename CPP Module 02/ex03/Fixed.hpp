#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt( void ) const;

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();		//pre-increment
		Fixed	operator++(int);	//post-increment
		Fixed&	operator--();		//pre-decrement
		Fixed	operator--(int);	//post-decrement

		static Fixed&		min(Fixed& x, Fixed& y);
		static const Fixed&	min(const Fixed& x, const Fixed& y);
		static Fixed&		max(Fixed& x, Fixed& y);
		static const Fixed&	max(const Fixed& x, const Fixed& y);
	private:
		int	rawBits;
		static const int fract;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif