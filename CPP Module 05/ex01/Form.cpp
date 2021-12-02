/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:15:57 by grusso            #+#    #+#             */
/*   Updated: 2021/12/02 18:46:43 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	checkGrade();
}

Form::Form(const Form& other) : _name(getName()), _signed(getSigned()), _signGrade(getSignGrade()), _execGrade(getExecGrade())
{
	*this = other;
}

Form::~Form() {}

const std::string&	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

int					Form::getExecGrade() const
{
	return (_execGrade);
}

int					Form::getSignGrade() const
{
	return (_signGrade);
}

void				Form::checkGrade()
{
	if (_signGrade < HIGHEST_VALUE || _execGrade < HIGHEST_VALUE)
		throw Form::GradeTooHighException();
	else if (_signGrade > LOWEST_VALUE || _execGrade > LOWEST_VALUE)
		throw Form::GradeTooLowException();
}

bool				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < _signGrade)
	{
		_signed = true;
		return (true);
	}
	else
	{
		_signed = false;
		return (false);
	}
}

Form	&Form::operator=(const Form& other)
{
	this->_signed = other._signed;
	std::cout << "Name and grades are const and can't be overwritten, only _signed was copied" << std::endl;

	return *this;
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
	os << form.getName() << " Form has to be signed by a "
		<< form.getSignGrade() << " grade and executed by a "
		<< form.getExecGrade() << " grade, it is "
		<< ((form.getSigned()) ? "" : "not ") << "signed";

	return (os);
}