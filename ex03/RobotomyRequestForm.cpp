/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:21 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/09 10:32:16 by eburnet          ###   ########.fr       */
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

void RobotomyRequestForm::action(Bureaucrat const &b) const
{
	try
	{
		this->execute(b);
		std::cout << "vvvvvvvv" << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy failed on " << this->target << std::endl;
	}
	catch(const std::exception& e)
	{
		throw ;
	}
}