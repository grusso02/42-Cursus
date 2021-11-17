#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

#define NC "\033[0m"
#define RED(x) "\033[31m" x NC
#define GREEN(x) "\033[32m" x NC
#define CYAN(x) "\033[36m" x NC

class contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class class_phonebook
{
	public:
		void		ft_add();
		void		set_firstName(std::string s);
		void		set_lastName(std::string s);
		void		set_nickname(std::string s);
		void		set_phoneNumber(std::string s);
		void		set_darkestSecret(std::string s);
		std::string	get_firstName(int i);
		std::string	get_lastName(int i);
		std::string	get_nickname(int i);
		std::string	get_phoneNumber(int i);
		std::string	get_darkestSecret(int i);
		void		ft_search();
		std::string	ft_substr(std::string s);
	private:
		contact	contacts[8];
		int		i;
};

#endif