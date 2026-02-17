/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldonstudent.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:46:52 by almaldon          #+#    #+#             */
/*   Updated: 2025/11/30 12:46:52 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	std::string	input;
	Phonebook	ph;

	std::cout << "Type a command (ADD, SEARCH, EXIT): ";
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			ph.add();
		else if (input == "SEARCH")
			ph.search();
		else if (input == "EXIT")
			break;
		std::cout << "Type a command (ADD, SEARCH, EXIT): ";
	}
	ph.exit();
	return (0);
}