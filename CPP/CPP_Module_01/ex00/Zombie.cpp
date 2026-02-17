/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:38:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 10:22:16 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Default Zombie Constructor called" << std::endl;
	this->name = "Default Zombie";
}

Zombie::Zombie(std::string name)
{
		std::cout << "Define Zombie Constructor called" << std::endl;
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