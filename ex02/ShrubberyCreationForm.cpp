/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:25 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 10:03:31 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm(137, 145, "ShrubberyCreationForm") 
{
	this->target = _target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getGradeExec(), other.getGradeSign(), other.getName())
{
	operator=(other);
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	this->target = other.target;
	this->is_signed = other.is_signed;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == true)
	{
		if (executor.getGrade() > this->grade_exec)
			throw AForm::GradeTooLowException();
	}
	else
		throw AForm::NotSignedException();
	std::string file_name = this->target + "_shrubbery.txt";
	std::ofstream outfile (file_name.c_str());
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
	outfile.close();
}
