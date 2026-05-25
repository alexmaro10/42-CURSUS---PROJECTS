/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:33:06 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/20 09:18:43 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
	std::cout << BIGGREEN << "\n========== FORM TEST ==========\n" << RESET << std::endl;
	
	{
		std::cout << CYAN << "\n[TEST 1] Correct ShrubberyCreationForm signed and execute\n" << RESET;
		Bureaucrat b1("Bob", 1);
		ShrubberyCreationForm sfc1("hola");
		b1.signForm(sfc1);
		b1.executeForm(sfc1);
		std::cout << sfc1 << std::endl;
	}
	{
		std::cout << CYAN << "\n[TEST 2] Correct RobotomyRequestForm signed and execute\n" << RESET;
		std::cout << std::endl;
		Bureaucrat b1("Bob", 1);
		RobotomyRequestForm rrf1("hola");
		b1.signForm(rrf1);
		b1.executeForm(rrf1);
		std::cout << rrf1 << std::endl;
	}
	{
		std::cout << CYAN << "\n[TEST 3] Correct PresidentialPardonForm signed and execute\n" << RESET;
		std::cout << std::endl;
		Bureaucrat b1("Bob", 1);
		PresidentialPardonForm ppf1("hola");
		b1.signForm(ppf1);
		b1.executeForm(ppf1);
		std::cout << ppf1 << std::endl;
	}
	{
		try {
			std::cout << CYAN << "\n[TEST 4] Too low grade to sign ShrubberyCreationForm\n" << RESET;
			Bureaucrat b1("Bob", 150);
			ShrubberyCreationForm sfc1("hola");
			b1.signForm(sfc1);
			b1.executeForm(sfc1);
			std::cout << sfc1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		try {
			std::cout << CYAN << "\n[TEST 5] Too low grade to execute ShrubberyCreationForm\n" << RESET;
			Bureaucrat b1("Bob", 145);
			ShrubberyCreationForm sfc1("hola");
			b1.signForm(sfc1);
			b1.executeForm(sfc1);
			std::cout << sfc1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << CYAN << "\n[TEST 6] Too low grade to sign RobotomyRequestForm\n" << RESET;
			Bureaucrat b1("Bob", 150);
			RobotomyRequestForm rrf1("hola");
			b1.signForm(rrf1);
			b1.executeForm(rrf1);
			std::cout << rrf1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << CYAN << "\n[TEST 7] Too low grade to execute RobotomyRequestForm\n" << RESET;
			Bureaucrat b1("Bob", 72);
			RobotomyRequestForm rrf1("hola");
			b1.signForm(rrf1);
			b1.executeForm(rrf1);
			std::cout << rrf1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << CYAN << "\n[TEST 8] Too low grade to sign PresidentialPardonForm\n" << RESET;
			Bureaucrat b1("Bob", 150);
			PresidentialPardonForm ppf1("hola");
			b1.signForm(ppf1);
			b1.executeForm(ppf1);
			std::cout << ppf1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << CYAN << "\n[TEST 9] Too low grade to execute PresidentialPardonForm\n" << RESET;
			Bureaucrat b1("Bob", 25);
			PresidentialPardonForm ppf1("hola");
			b1.signForm(ppf1);
			b1.executeForm(ppf1);
			std::cout << ppf1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		try {
			std::cout << CYAN << "\n[TEST 10] Try to execute ShrubberyCreationForm without sign it\n" << RESET;
			Bureaucrat b1("Bob", 1);
			ShrubberyCreationForm sfc1("hola");
			b1.executeForm(sfc1);
			std::cout << sfc1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << CYAN << "\n[TEST 11] Try to execute RobotomyRequestForm without sign it\n" << RESET;
			Bureaucrat b1("Bob", 1);
			RobotomyRequestForm rrf1("hola");
			b1.executeForm(rrf1);
			std::cout << rrf1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		try {
			std::cout << CYAN << "\n[TEST 12] Try to execute PresidentialPardonForm without sign it\n" << RESET;
			Bureaucrat b1("Bob", 1);
			PresidentialPardonForm ppf1("hola");
			b1.executeForm(ppf1);
			std::cout << ppf1 << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
