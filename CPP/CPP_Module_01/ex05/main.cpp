/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:10:28 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 09:15:16 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::cout << "####### CONSTRUCTORS #######" << std::endl;
	Harl h;

	std::cout << std::endl <<"####### HARL TESTS #######" << std::endl;
	h.complain("DEBUG");
	std::cout << std::endl;
	h.complain("INFO");
	std::cout << std::endl;
	h.complain("WARNING");
	std::cout << std::endl;
	h.complain("ERROR");
	std::cout << std::endl;
	h.complain("BURGUER");
	std::cout << std::endl << std::endl;
	
	std::cout << "####### DESTRUCTORS #######" << std::endl;

	return (0);
}