/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:02 by grusso            #+#    #+#             */
/*   Updated: 2021/12/02 18:46:03 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(getName()), _grade(getGrade())
{
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

void				Bureaucrat::incrGrade()
{
	_grade--;
	checkGrade();
}

void				Bureaucrat::decrGrade()
{
	_grade++;
	checkGrade();
}

void				Bureaucrat::checkGrade()
{
	if (_grade < HIGHEST_VALUE)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > LOWEST_VALUE)
		throw Bureaucrat::GradeTooLowException();
}

bool				Bureaucrat::signForm(Form& form)
{
	if (form.beSigned(*this))
	{
		std::cout << _name << " signs " << form.getName() << std::endl;
		return (true);
	}
	else
	{
		std::cout << _name << " cannot signs " << form.getName() << " because his grade is not high enough" << std::endl;
		return (false);
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	this->_grade = other._grade;
	std::cout << "Name is const and can't be overwritten, only grade was copied" << std::endl;

	return (*this);
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}