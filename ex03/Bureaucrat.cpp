/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:42 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 09:56:11 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::grade_increment()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade--;
}

void Bureaucrat::grade_decrement()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade++;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	Bureaucrat::operator=(other);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return os; 
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << this->name << " couldn't signed " << f.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
	std::cout << this->name << " executed " << form.getName() << std::endl;
}
