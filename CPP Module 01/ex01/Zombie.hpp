#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void		setName(std::string name);
		std::string	getName();
		void		announce(void);
	private:
		std::string	_nameZombie;
};

Zombie*	zombieHorde(int N, std::string name);

#endif