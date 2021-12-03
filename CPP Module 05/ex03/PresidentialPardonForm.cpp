/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:54:40 by grusso            #+#    #+#             */
/*   Updated: 2021/12/03 15:35:15 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

# define NAME "PresidentialPardonForm"
# define REQ_SIGN 25
# define REQ_EXEC 5

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(getTarget())
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void					PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	checkExecutable(executor);

	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	std::cout << "Can't copy anything" << std::endl;
	other.getTarget();

	return *this;
}