#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define HIT_POINTS		10
# define ENERGY_POINTS	10
# define ATTACK_DAMAGE	10

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif