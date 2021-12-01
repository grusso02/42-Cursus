#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define INV_SIZE 4

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character& other);
		~Character();

		Character& operator=(const Character& other);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string	_name;
		AMateria**	_inventory;
};

#endif