/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:56:01 by eburnet           #+#    #+#             */
/*   Updated: 2025/03/27 13:05:59 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
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
		void action(Bureaucrat const &b) const;
};