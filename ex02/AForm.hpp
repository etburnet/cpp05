/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:38:43 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 10:01:32 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Bureaucrat;

class AForm
{
	protected:
		std::string const name;
		bool is_signed;
		int const grade_exec;
		int const grade_sign;
	public:
		AForm(int g_exec, int g_sign, std::string _name);
		virtual ~AForm() = 0;
		AForm(const AForm &);
		AForm& operator=(const AForm &);
		std::string getName() const;
		int getGradeExec() const;
		int getGradeSign() const;
		bool getIsSigned() const;
		virtual void execute(Bureaucrat const &executor) const = 0;
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
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Form isn't signed!";
				}
		};
};

std::ostream& operator<<(std::ostream&os, const AForm&);
