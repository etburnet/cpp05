/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:40 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/26 16:06:28 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::cout << "-----------Sign form Grade trop bas-----------" << std::endl;
	Bureaucrat ethan("ethan", 15);
	Form *a = new ShrubberyCreationForm("home");
	try
	{
		ethan.signForm(*a);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	std::cout << ethan << std::endl;
	return (0);
}