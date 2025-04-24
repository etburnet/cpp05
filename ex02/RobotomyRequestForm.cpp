/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:21 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 10:03:26 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm(45, 72, "RobotomyRequestForm") 
{
	this->target = _target;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getGradeExec(), other.getGradeSign(), other.getName())
{
	operator=(other);
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	this->target = other.target;
	this->is_signed = other.is_signed;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == true)
	{
		if (executor.getGrade() > this->grade_exec)
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::NotSignedException();
	std::cout << "vvvvvvvv" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->target << std::endl;
}