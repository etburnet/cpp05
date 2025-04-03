/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:23 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/27 13:06:04 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
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
		void action(Bureaucrat const &b) const;
};