/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:33:32 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/06 08:49:20 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int	main()
{
	std::cout << "##############################" << std::endl;
	std::cout << "#                            #" << std::endl;
	std::cout << "#                            #" << std::endl;
	std::cout << "# " << MAGENTA <<"CLAPTRAP INSTRUCTION COLOR" << RESET << " #" << std::endl;
	std::cout << "#                            #" << std::endl;
	std::cout << "# " << CYAN <<"SCAVTRAP INSTRUCTION COLOR" << RESET << " #" << std::endl;
	std::cout << "#                            #" << std::endl;
	std::cout << "#                            #" << std::endl;
	std::cout << "##############################" << std::endl << std::endl;
	
	std::cout << "####### CONSTRUCTORS #######" << std::endl << std::endl;
	ScavTrap c1;
	ScavTrap c2("S_Kal");
	ScavTrap c3(c1);
	ScavTrap c4;

	c4 = c2;

	std::cout << std::endl << "####### ATTACKS #######" << std::endl << std::endl;
	for (int i = 0; i <= 50; i++)
	{
		std::cout << i + 1 << ": ";
		c2.attack("Default");
	}
	
	std::cout << std::endl << "####### DAMAGE #######" << std::endl << std::endl;
	for (int i = 0; i < 6; i++) 
	{
		std::cout << i + 1 << ": ";
		c4.takeDamage(20);
	}

	std::cout << std::endl << "####### REPAIR #######" << std::endl << std::endl;
	for (int i = 0; i <= 50; i++)
	{
		std::cout << i + 1 << ": ";
		c1.beRepaired(1);
	}

	std::cout << std::endl << "####### GUARD GATE #######" << std::endl << std::endl;
	c1.guardGate();
	c2.guardGate();
	c3.guardGate();
	c4 = c2;
	c4.guardGate();
	
	std::cout << std::endl << "####### IS DEAD #######" << std::endl << std::endl;
	c1.attack("Kal");
	c1.beRepaired(1);
	c1.takeDamage(1);
	
	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl << std::endl;
	return (0);
}