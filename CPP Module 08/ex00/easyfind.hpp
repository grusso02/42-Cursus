#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template<typename T>
bool	easyfind(T& container, int x)
{
	typename T::iterator ret_it = std::find(container.begin(), container.end(), x);

	if (ret_it == container.end())
		return false;
	return true;
}

#endif