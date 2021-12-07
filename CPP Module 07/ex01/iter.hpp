#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T* array, int n, void (*f)(const T& elem))
{
	for (int i = 0; i < n; i++)
		(*f)(array[i]);
}

template<typename T>
void	ft_print(const T& elem)
{
	std::cout << elem << " ";
}

#endif