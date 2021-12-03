/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:40:33 by grusso            #+#    #+#             */
/*   Updated: 2021/12/03 16:53:29 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Form*	Intern::makeForm(std::string form, std::string target) const
{
/* 	t_formList formList[] =
	{
		{"shruberry creation", new ShruberryCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"", nullptr}
	};
	Form* resultForm = nullptr;

	for (size_t i = 0; formList->formType != nullptr; i++)
	{
		if (formList[i].formName == form)
			resultForm = formList[i].formType;
		else
			delete formList[i].formType;
	}

	if (resultForm == nullptr)
		std::cout << "Form not found" << std::endl;
	else
		std::cout << "Intern creates " << form << std::endl; */

	enum forms {SHRUBERRY, ROBOTOMY, PRESIDENTIAL};
	std::string		_formName[4] = {"shruberry creation", "robotomy request", "presidential pardon", "\0"};
	Form*	resultForm = nullptr;
	int		i = 0;

	for (; _formName[i] != "\0";)
	{
		if (_formName[i] == form)
			break ;
		i++;
	}

	switch (i)
	{
		case SHRUBERRY:
			resultForm = new ShruberryCreationForm(target);
			break;
		case ROBOTOMY:
			resultForm = new RobotomyRequestForm(target);
			break;
		case PRESIDENTIAL:
			resultForm = new PresidentialPardonForm(target);
			break;
		default:
			break;
	}

	if (resultForm == nullptr)
		std::cout << "Form not found" << std::endl;
	else
		std::cout << "Intern creates " << form << std::endl;

	return (resultForm);
}