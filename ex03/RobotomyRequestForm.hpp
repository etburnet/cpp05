/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:23 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 10:03:23 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "iostream"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm & operator=(const RobotomyRequestForm &);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;

};