/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:57:53 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/04 08:34:44 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << CYAN << "Default FragTrap was created" << RESET << std::endl;
	this->name = "F_Bot";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN << "FrafTrap named " << name << " was created" << RESET << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << CYAN << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.getName();
		this->hit_points = copy.getHitPoints();
		this->attack_damage = copy.getAttackDamage();
		this->energy_points = copy.getEnergyPoints();
	}
	std::cout << CYAN << "FragTrap Assignation operator called" << RESET << std::endl;
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << CYAN << this->name << " FragTrap was detroyed" << RESET << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FragTrap " << this->name << ": High Five Guys!!" << RESET << std::endl;
}