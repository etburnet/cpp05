/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:55:58 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 10:03:16 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm(5, 25, "PresidentialPardonForm")
{
	this->target = _target;
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getGradeExec(), other.getGradeSign(), other.getName())
{
	operator=(other);
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	this->is_signed = other.getIsSigned();
	this->target = other.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == true)
	{
		if (executor.getGrade() > this->grade_exec)
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::NotSignedException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
