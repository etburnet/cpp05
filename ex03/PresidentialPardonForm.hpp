/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:01 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 10:03:14 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "iostream"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm & operator=(const PresidentialPardonForm &);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};