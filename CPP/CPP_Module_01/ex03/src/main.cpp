/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:36:57 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/09 10:58:06 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int	main(void)
{
	std::cout << "####### HUMANA TESTS #######" << std::endl << std::endl;
	Weapon wp("sword");
	HumanA ha("Bob", wp);
	
	ha.attack();
	wp.setType("gun");
	ha.attack();

	std::cout << std::endl <<"####### HUMANB TESTS #######" << std::endl << std::endl;
	HumanB hb("Tal");
	hb.attack();
	hb.setWeapon(wp);
	hb.attack();
	wp.setType("bow");
	hb.attack();

	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl << std::endl;
}