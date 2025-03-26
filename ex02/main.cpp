/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:40 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/26 14:14:14 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "-----------Sign form Grade ok-----------" << std::endl;
	try
	{
		Bureaucrat ethan("ethan", 15);
		Form cdi(1, 15, "cdi");
		ethan.signForm(cdi);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------Sign form Grade trop bas-----------" << std::endl;
	Bureaucrat ethan("ethan", 15);
	Form cdi(1, 15, "cdi");
	try
	{
		ethan.signForm(cdi);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << cdi << std::endl;
	std::cout << ethan << std::endl;
	return (0);
}