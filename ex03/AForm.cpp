/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:38:47 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/27 13:56:26 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(int g_exec, int g_sign, std::string _name) : name(_name), grade_exec(g_exec), grade_sign(g_sign)
{
	if(grade_exec > 150 || grade_sign > 150)
		throw AForm::GradeTooHighException();
	else if (grade_exec < 1 || grade_sign < 1)
		throw AForm::GradeTooLowException();
	this->is_signed = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : name(other.name), grade_exec(other.grade_exec), grade_sign(other.grade_sign)
{
	AForm::operator=(other);
}

AForm& AForm::operator=(const AForm &other)
{
	this->is_signed = other.is_signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getGradeExec() const
{
	return (this->grade_exec);
}

int AForm::getGradeSign() const
{
	return (this->grade_sign);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

void AForm::beSigned(Bureaucrat &b)
{
	int b_grade = b.getGrade();
	if (b_grade > this->grade_sign)
		throw AForm::GradeTooLowException();
	else
		is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm &other)
{
	os << other.getName() << " need grade: " << other.getGradeSign() << " to be signed & grade: " << other.getGradeExec() << " to be exec, is it signed: " << other.getIsSigned();
	return os; 
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == true)
	{
		if (executor.getGrade() > this->grade_exec)
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::NotSignedException();
}
