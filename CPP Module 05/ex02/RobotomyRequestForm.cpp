/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:53:39 by grusso            #+#    #+#             */
/*   Updated: 2021/12/03 15:24:31 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

# define NAME "RobotomyRequestForm"
# define REQ_SIGN 72
# define REQ_EXEC 45

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(getTarget())
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void				RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	checkExecutable(executor);

	std::cout << "* Unbearable drilling noises *" << std::endl;
	srand(time(NULL));
	if (std::rand() % 2)
		std::cout << "The robotomization on " << _target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "The robotomization on " << _target << " may or may not have been a complete and utter failure" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	std::cout << "Can't copy anything" << std::endl;
	other.getTarget();

	return *this;
}