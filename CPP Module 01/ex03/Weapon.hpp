#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "iostream"
#include "string"

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void			setType(std::string str);
		const std::string&	getType();
	private:
		std::string	_type;
};

#endif