/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:52:31 by grusso            #+#    #+#             */
/*   Updated: 2021/12/03 15:16:34 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

# define NAME "ShruberryCreationForm"
# define REQ_SIGN 145
# define REQ_EXEC 137

ShruberryCreationForm::ShruberryCreationForm(const std::string target) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(target) {}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& other) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(getTarget())
{
	*this = other;
}

ShruberryCreationForm::~ShruberryCreationForm() {}

const std::string	ShruberryCreationForm::getTarget() const
{
	return (_target);
}

void				ShruberryCreationForm::execute( const Bureaucrat &executor ) const
{
	checkExecutable(executor);

	std::string out = _target + "_shruberry";
	std::ofstream	fdOut(out);

	fdOut << "                                                         .";
	fdOut << "\n                                              .         ;  ";
	fdOut << "\n                 .              .              ;%     ;;   ";
	fdOut << "\n                   ,           ,                :;%  %;   ";
	fdOut << "\n                    :         ;                   :;%;'     .,   ";
	fdOut << "\n           ,.        %;     %;            ;        %;'    ,;";
	fdOut << "\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'";
	fdOut << "\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' ";
	fdOut << "\n               ;%;      %;        ;%;        % ;%;  ,%;'";
	fdOut << "\n                `%;.     ;%;     %;'         `;%%;.%;'";
	fdOut << "\n                 `:;%.    ;%%. %@;        %; ;@%;%'";
	fdOut << "\n                    `:%;.  :;bd%;          %;@%;'";
	fdOut << "\n                      `@%:.  :;%.         ;@@%;'   ";
	fdOut << "\n                        `@%.  `;@%.      ;@@%;         ";
	fdOut << "\n                          `@%%. `@%%    ;@@%;        ";
	fdOut << "\n                            ;@%. :@%%  %@@%;       ";
	fdOut << "\n                              %@bd%%%bd%%:;     ";
	fdOut << "\n                                #@%%%%%:;;";
	fdOut << "\n                                %@@%%%::;";
	fdOut << "\n                                %@@@%(o);  . '         ";
	fdOut << "\n                                %@@@o%;:(.,'         ";
	fdOut << "\n                            `.. %@@@o%::;         ";
	fdOut << "\n                               `)@@@o%::;         ";
	fdOut << "\n                                %@@(o)::;        ";
	fdOut << "\n                               .%@@@@%::;         ";
	fdOut << "\n                               ;%@@@@%::;.          ";
	fdOut << "\n                              ;%@@@@%%:;;;. ";
	fdOut << "\n                          ...;%@@@@@%%:;;;;,..    ";

	fdOut.close();
}

ShruberryCreationForm&	ShruberryCreationForm::operator=(ShruberryCreationForm const& other)
{
	std::cout << "Can't copy anything" << std::endl;
	other.getTarget();

	return *this;
}
