#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "Form.hpp"

# define NAME "ShruberryCreationForm"
# define REQ_SIGN 145
# define REQ_EXEC 137

class ShruberryCreationForm : public Form
{
	public:
		ShruberryCreationForm(const std::string _target);
		~ShruberryCreationForm();
	private:
		const std::string _target;
};


#endif