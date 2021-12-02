#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string _name, int signGrade, int execGrade);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getExecGrade() const;
		int					getSignGrade() const;
		void				checkGrade();
		bool				beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high: the maximum allowed value is 1");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low: the minimum allowed value is 150");
				}
		};
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif