/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:06:24 by grusso            #+#    #+#             */
/*   Updated: 2021/12/03 15:34:48 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Form			*form = NULL;
	Bureaucrat		bob("bob", 130);
	Bureaucrat		phil("phil", 40);
	Bureaucrat		luc("luc", 1);

	std::cout << "-----ShruberryCreationForm-----" << std::endl;
	try
	{
		form = new ShruberryCreationForm("28C");
		bob.signForm(*form);
		bob.executeForm(*form);
		delete form;
		form = NULL; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----RobotomyRequestForm-----" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28C");
		phil.signForm(*form);
		phil.executeForm(*form);
		delete form;
		form = NULL; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-----PresidentialPardonForm-----" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28C");
		luc.signForm(*form);
		luc.executeForm(*form);
		delete form;
		form = NULL; 
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
