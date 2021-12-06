#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

# define ZERO 0
# define FLOAT 1
# define DOUBLE 2
# define INT 3
# define CHAR 4

class Convert
{
    public:
        Convert(std::string str);
        ~Convert();

        void    toChar() const;
        void    toInt() const;
        void    toFloat() const;
        void    toDouble() const;
    private:
        std::string _str;
        int         flag;
        double      nb;
        char        c;
};

std::ostream& operator<<(std::ostream& os, Convert const& convert);

#endif