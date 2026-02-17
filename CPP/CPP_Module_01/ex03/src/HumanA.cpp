/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:19:42 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 09:34:36 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp) : name(name), wp(wp)
{
	std::cout << "HumanA " << this->name << " was created with " << this->wp.getType() << " type of weapon" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->name << " deleted " << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with his/her " << this->wp.getType() << std::endl;
}
