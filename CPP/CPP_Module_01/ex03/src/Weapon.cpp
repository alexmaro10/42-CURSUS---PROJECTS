/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:09:27 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 09:35:28 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(void)
{
	this->type = "default weapon";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << this->type << " weapon deleted" << std::endl;
}

std::string Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}