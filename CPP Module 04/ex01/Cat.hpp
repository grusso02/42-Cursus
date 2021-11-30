#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();
		Cat& operator=(const Cat& other);
		std::string	getType() const;
		void makeSound() const;
		Brain*	getBrain() const;
	private:
		Brain* _brain;
};

#endif