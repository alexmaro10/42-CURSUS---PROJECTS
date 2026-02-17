/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:32:28 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 09:34:47 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), wp(NULL)
{
	std::cout << "HumanB " << name << " was created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->name << " deleted " << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
	this->wp = &wp;
}

void HumanB::attack(void)
{
	if (wp)
		std::cout << this->name << " attacks with his/her " << this->wp->getType() << std::endl;
	else
		std::cout << this->name << " can not attacks because he/she doesn't have any weapon type" << std::endl;
}