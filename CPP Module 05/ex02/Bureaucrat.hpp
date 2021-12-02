#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

# define HIGHEST_VALUE 1
# define LOWEST_VALUE 150

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		std::string	getName() const;
		int			getGrade() const;
		void				incrGrade();
		void				decrGrade();
		void				checkGrade();
		bool				signForm(Form& form);

	private:
		const std::string	_name;
		int					_grade;

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

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif