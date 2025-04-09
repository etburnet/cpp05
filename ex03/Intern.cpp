/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:45:37 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/09 10:32:03 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	operator=(other);
}

Intern & Intern::operator=(const Intern &other)
{
	return(*this);
}

Intern::~Intern()
{
}

AForm *makePresident(std::string f_target)
{
	return (new PresidentialPardonForm(f_target));
}

AForm *makeRobotomy(std::string f_target)
{
	return (new RobotomyRequestForm(f_target));
}

AForm *makeShrubbery(std::string f_target)
{
	return (new ShrubberyCreationForm(f_target));
}

AForm *Intern::makeForm(std::string f_name, std::string f_target)
{
	AForm *(*ptrFctTab[])(std::string f_target) = {&makePresident, &makeRobotomy, &makeShrubbery};
	std::string form_name[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};


	for (size_t i = 0; i < 4; i++)
	{
		if (f_name == form_name[i])
		{
			std::cout << "Intern creates " << f_name << std::endl;
			return (ptrFctTab[i](f_target));
		}
	}
	std::cout << "This Form doesn't exist (existing forms: Presidential Pardon, Robotomy Request, Shrubbery Creation" << std::endl;
	return (NULL);
}