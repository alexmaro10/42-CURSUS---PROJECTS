/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:39:29 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/12 09:09:28 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "####### CONSTRUCTORS #######" << std::endl;
	int	N = 5;
	Zombie *horde = zombieHorde(N, "Bob");

	std::cout << std::endl << "####### HORDE TESTS #######" << std::endl;
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	
	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl;
	delete[] horde;
}