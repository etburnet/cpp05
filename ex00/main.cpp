/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:40 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/26 14:03:34 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "-----------Test Grade trop faible-----------" << std::endl;
	try
	{
		Bureaucrat ethan("ethan", -5);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------Test Grade trop elever-----------" << std::endl;
	try
	{
		Bureaucrat ethan("ethan", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------Test increment Grade trop elever-----------" << std::endl;
	try
	{
		Bureaucrat ethan("ethan", 1);
		ethan.grade_increment();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------Test increment Grade trop elever-----------" << std::endl;
	try
	{
		Bureaucrat ethan("ethan", 1);
		ethan.grade_increment();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------Test increment decrement et surchage d'operateur <<-----------" << std::endl;
	Bureaucrat ethan("ethan", 5);
	try
	{
		ethan.grade_increment();
		ethan.grade_decrement();
		ethan.grade_decrement();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << ethan << std::endl;
}