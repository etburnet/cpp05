/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:38:47 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/27 09:08:13 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(int g_exec, int g_sign, std::string _name) : name(_name), grade_exec(g_exec), grade_sign(g_sign)
{
	if(grade_exec > 150 || grade_sign > 150)
		throw Form::GradeTooHighException();
	else if (grade_exec < 1 || grade_sign < 1)
		throw Form::GradeTooLowException();
	this->is_signed = false;
}

Form::~Form()
{
}

Form::Form(const Form &other) : name(other.name), grade_exec(other.grade_exec), grade_sign(other.grade_sign)
{
	Form::operator=(other);
}

Form& Form::operator=(const Form &other)
{
	this->is_signed = other.is_signed;
	return (*this);
}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeExec() const
{
	return (this->grade_exec);
}

int Form::getGradeSign() const
{
	return (this->grade_sign);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

void Form::beSigned(Bureaucrat &b)
{
	int b_grade = b.getGrade();
	if (b_grade > this->grade_sign)
		throw Form::GradeTooLowException();
	else
		is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form &other)
{
	os << other.getName() << " need grade: " << other.getGradeSign() << " to be signed & grade: " << other.getGradeExec() << " to be exec, is it signed: " << other.getIsSigned();
	return os; 
}
