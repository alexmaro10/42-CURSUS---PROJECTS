/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:33:32 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/06 08:49:05 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	std::cout << "####### CONSTRUCTORS #######" << std::endl << std::endl;
	ClapTrap c1;
	ClapTrap c2("Kal");
	ClapTrap c3(c1);
	ClapTrap c4;

	c4 = c2;

	std::cout << std::endl << "####### ATTACKS #######" << std::endl << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		std::cout << i + 1 << ": ";
		c2.attack("Default");
	}
	
	std::cout << std::endl << "####### DAMAGE #######" << std::endl << std::endl;
	for (int i = 0; i < 11; i++) 
	{
		std::cout << i + 1 << ": ";
		c1.takeDamage(1);
	}

	std::cout << std::endl << "####### REPAIR #######" << std::endl << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		std::cout << i + 1 << ": ";
		c4.beRepaired(1);
	}

	std::cout << std::endl << "####### IS DEAD #######" << std::endl << std::endl;
	c1.attack("Kal");
	c1.beRepaired(1);
	c1.takeDamage(1);
	
	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl << std::endl;
	return (0);
}