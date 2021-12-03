#ifndef INTERN_HPP
# define INTERN_HPP

# include "iostream"
# include "string"

# include "Form.hpp"
# include "ShruberryCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();

		Form*	makeForm(std::string form, std::string target) const;
	private:
/* 		typedef struct	s_formList
		{
			std::string formName;
			Form*		formType;
		}				t_formList; */
		std::string		_formName[3];
};

#endif