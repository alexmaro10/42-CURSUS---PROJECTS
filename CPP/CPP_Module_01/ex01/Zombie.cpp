/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:38:46 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 09:25:33 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Default Zombie Constructor Called" << std::endl;
	this->name = "Default Zombie";
}

Zombie::Zombie(std::string name)
{
	std::cout << "Define Name Zombie Constructor Called" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed"<< std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}