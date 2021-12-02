/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grusso <grusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:52:31 by grusso            #+#    #+#             */
/*   Updated: 2021/12/02 19:21:09 by grusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(const std::string target) : Form(NAME, REQ_EXEC, REQ_EXEC), _target(target) {}

ShruberryCreationForm::~ShruberryCreationForm() {}