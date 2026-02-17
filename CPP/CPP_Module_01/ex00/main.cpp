/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:52:03 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/12 08:41:09 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "########## BASIC TESTS ##########" << std::endl << std::endl;
	Zombie z1;
	Zombie z2("Bob");

	z1.announce();
	z2.announce();

	std::cout << std::endl << "########## NEWZOMBIE TESTS ##########" << std::endl << std::endl;
	Zombie *z3 = newZombie("Raul");
	z3->announce();

	std::cout << std::endl << "########## NEWCHUMP TESTS ##########" << std::endl << std::endl;
	randomChump("Chump");

	std::cout << std::endl << "########## DESTRUCTORS ##########" << std::endl << std::endl;
	delete(z3);
}