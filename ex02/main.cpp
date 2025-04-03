/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:40 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/27 14:41:34 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::srand(time(NULL));
	std::cout << "-----------ex before sign-----------" << std::endl;
	Bureaucrat ethan("ethan", 15);
	AForm *a = new ShrubberyCreationForm("home");
	try
	{
		ethan.executeForm(*a); 
		ethan.signForm(*a);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------sign before ex-----------" << std::endl;
	try
	{
		ethan.signForm(*a);
		ethan.executeForm(*a);

	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *a << std::endl;
	std::cout << ethan << std::endl;

	std::cout << std::endl;
	std::cout << "-----------grade to low for signing Form-----------" << std::endl;
	Bureaucrat tom("tom", 74);
	AForm *b = new RobotomyRequestForm("titouan");
	try
	{
		tom.signForm(*b);
		ethan.signForm(*b);
		ethan.executeForm(*b);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *b << std::endl;
	std::cout << tom << std::endl;

	std::cout << std::endl;
	std::cout << "-----------Form-----------" << std::endl;
	Bureaucrat philipe("philipe", 1);
	AForm *c = new PresidentialPardonForm("eric");
	try
	{
		philipe.signForm(*c);
		philipe.executeForm(*c);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *c << std::endl;
	std::cout << philipe << std::endl;
	delete a;
	delete b;
	delete c;
	return (0);
}