/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:34:44 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/27 12:23:12 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "string"
#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
	public:
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat& operator=(const Bureaucrat &);
		~Bureaucrat();
		int getGrade() const;
		std::string getName() const;
		void grade_increment();
		void grade_decrement();
		void signForm(AForm &);
		void executeForm(AForm const & form);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Grade too high!";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Grade too low!";
				}
		};
};

std::ostream& operator<<(std::ostream&os, const Bureaucrat&);
