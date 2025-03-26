/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:38:43 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/26 14:50:45 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string const name;
		bool is_signed;
		int const grade_exec;
		int const grade_sign;
	public:
		Form(int g_exec, int g_sign, std::string _name);
		virtual ~Form() = 0;
		Form(const Form &);
		Form& operator=(const Form &);
		std::string getName() const;
		int getGradeExec() const;
		int getGradeSign() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat &b);
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

std::ostream& operator<<(std::ostream&os, const Form&);
