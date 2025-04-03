/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:40 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/28 11:08:43 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	std::srand(time(NULL));
	std::cout << "-----------Inern test-----------" << std::endl;
	Bureaucrat ethan("ethan", 15);
	AForm *a;
	Intern thimotee;
	a = thimotee.makeForm("Presidential Pardon", "louis");
	try
	{
		ethan.signForm(*a);
		ethan.executeForm(*a);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete a;
	return (0);
}