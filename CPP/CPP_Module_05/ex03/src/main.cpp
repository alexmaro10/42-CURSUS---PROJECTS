/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:33:06 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/20 10:27:15 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

int main()
{
	Intern i1;
	AForm *f1;
	Bureaucrat b1("Alex", 1);

	std::cout << CYAN << "\n[TEST 1] Make, sign and execute RobotomyRequestForm\n" << RESET;
	f1 = i1.makeForm("RoBotomyRequest", "Luis");
	if (f1)
		std::cout << *f1 << std::endl;
	b1.signForm(*f1);
	b1.executeForm(*f1);
	delete f1;
	std::cout << CYAN << "\n[TEST 2] Make, sign and execute PresidentialPardonForm\n" << RESET;
	f1 = i1.makeForm("PRESIDENTIALpARDON", "Luis");
	if (f1)
		std::cout << *f1  << std::endl;
	b1.signForm(*f1);
	b1.executeForm(*f1);
	delete f1;
	std::cout << CYAN << "\n[TEST 3] Make, sign and execute ShrubberyCreationForm\n" << RESET;
	f1 = i1.makeForm("ShrubberyCreation", "Luis");
	if (f1)
		std::cout << *f1  << std::endl;
	b1.signForm(*f1);
	b1.executeForm(*f1);
	delete f1;
	return (0);
}