#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();

		const std::string	getName() const;
		const int			getGrade() const;

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

#endif