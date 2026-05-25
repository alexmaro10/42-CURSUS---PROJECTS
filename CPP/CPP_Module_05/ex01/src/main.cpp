/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:33:06 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/20 09:05:15 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int main()
{
	std::cout << BIGGREEN << "\n========== BUREAUCRAT TEST ==========\n" << RESET << std::endl;

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
		std::cerr << RED << e.what() << RESET << std::endl;
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
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 3] Creation with grade too low\n" << RESET;
		Bureaucrat b1("Pepe", 151);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 4] Creation with negative grade\n" << RESET;
		Bureaucrat b1("Miguel", -3);
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << BIGGREEN << "\n========== FORM TEST ==========\n" << RESET << std::endl;

	try
	{
		std::cout << CYAN << "\n[TEST 5] Form - Sign grade too high\n" << RESET;
		Form f1("Test", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 6] Form - Execute grade too high\n" << RESET;
		Form f1("Test", 150, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 7] Form - Execute grade too low\n" << RESET;
		Form f1("Test", 150, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 8] Form - Sign grade too low\n" << RESET;
		Form f1("Test", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 9] Signing with insufficient grade\n" << RESET;
		Form f1("Test", 1, 1);
		Bureaucrat b1("Alex", 12);

		std::cout << "Bureaucrat: " << b1 << std::endl;
		std::cout << "Form:\n" << f1;

		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "\n[TEST 10] Successful signing\n" << RESET;
		Form f1("Test", 50, 26);
		Bureaucrat b1("Alex", 12);

		std::cout << "Bureaucrat: " << b1 << std::endl;
		std::cout << "Initial form:\n" << f1;

		b1.signForm(f1);

		std::cout << "Form after signing:\n" << f1;

		b1.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << BIGGREEN << "\n========== END OF TESTS ==========\n" << RESET << std::endl;

	return 0;
}