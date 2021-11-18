#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		void	randomChump( std::string name );
	private:
		std::string	nameZombie;
};

Zombie*	newZombie(std::string name);

#endif