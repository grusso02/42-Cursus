#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShruberryCreationForm : public Form
{
	public:
		ShruberryCreationForm(const std::string _target);
		ShruberryCreationForm(const ShruberryCreationForm& other);
		~ShruberryCreationForm();

		ShruberryCreationForm& operator=(const ShruberryCreationForm& other);

		const std::string	getTarget() const;
		void				execute( const Bureaucrat &executor ) const;
	private:
		const std::string _target;
};

#endif