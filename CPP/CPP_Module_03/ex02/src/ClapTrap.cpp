/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:03:38 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/04 10:28:44 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << MAGENTA << "Default ClapTrap was created" << RESET << std::endl;
	this->name = "Bot";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << MAGENTA << "ClapTrap named " << name << " was created" << RESET << std::endl;
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << MAGENTA << "Copy constructor called" << RESET << std::endl;
	this->name = copy.getName();
	this->hit_points = copy.getHitPoints();
	this->energy_points = copy.getEnergyPoints();
	this->attack_damage = copy.getAttackDamage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << MAGENTA << "ClapTrap Assignation operator called" << RESET << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hit_points = copy.hit_points;
		this->energy_points = copy.energy_points;
		this->attack_damage = copy.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << MAGENTA << this->name << " ClapTrap was detroyed" << RESET << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

int	ClapTrap::getHitPoints() const
{
	return (this->hit_points);
}

int	ClapTrap::getEnergyPoints() const
{
	return (this->energy_points);
}

int	ClapTrap::getAttackDamage() const
{
	return (this->attack_damage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << MAGENTA << "ClapTrap " << this->name << " attacks " << target
		<< " causing " << this->attack_damage << " points of damage!" << RESET << std::endl;
	}
	else if (this->energy_points == 0)
	{
		std::cout << MAGENTA << "ClapTrap " << this->name
		<< " cannot attack because it has no energy points." << RESET << std::endl;
	}
	else
	{
		std::cout << MAGENTA << "ClapTrap " << this->name
		<< " cannot attack because it is dead." << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		this->hit_points += amount;
		std::cout << MAGENTA << "ClapTrap " << this->name << " repaired itself " << amount
		<< " hit points!" << RESET << std::endl;
	}
	else if (this->energy_points == 0)
	{
		std::cout << MAGENTA << "ClapTrap " << this->name
		<< " cannot repair itself because it has no energy points." << RESET << std::endl;
	}
	else
	{
		std::cout << MAGENTA << "ClapTrap " << this->name
		<< " cannot repair itself because it is dead" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
		if (this->hit_points - amount >= 0)
			this->hit_points -= amount;
		else
		{
			amount = this->hit_points;
			this->hit_points = 0;
		}
		if (hit_points > 0)
		{
			std::cout << MAGENTA << "ClapTrap " << this->name << " was attacked and lost "
			<< amount << " hit points" << RESET << std::endl;
		}
		else
			std::cout << MAGENTA << "ClapTrap " << this->name << " was attacked and lost "
			<< amount << " hit points and died" << RESET << std::endl;
	}
	else
		std::cout << MAGENTA << "ClapTrap " << this->name << " is died" << RESET << std::endl;
}
