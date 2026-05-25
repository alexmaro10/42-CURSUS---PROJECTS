/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 08:44:09 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/16 08:49:36 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);
		~Intern();

		AForm *makeForm(const std::string name, const std::string target);
};