/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:33:06 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/20 09:04:51 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
	std::cout << BIGGREEN << "\n========== BUREAUCRAT TEST ==========" << RESET << std::endl;

	try
	{
		std::cout << CYAN << "\n[TEST 1] Increment Grade upper limit\n" << RESET;
		Bureaucrat b1("Pedro", 2);

		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 2] Decrement Grade lower limit\n" << RESET;
		Bureaucrat b1("Jose", 149);

		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 3] Creation with grade too low\n" << RESET;
		Bureaucrat b1("Pepe", 151);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 4] Creation with grade 0\n" << RESET;
		Bureaucrat b1("Miguel", 0);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 5] Creation with negative grade\n" << RESET;
		Bureaucrat b1("Miguel", -3);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
}