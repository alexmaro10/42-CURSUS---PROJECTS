/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:03:20 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/04 10:28:23 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << CYAN << "Default ScavTrap was created" << RESET << std::endl;
	this->name = "S_Bot";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard_gate_mode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << CYAN <<  "ScavTrap named " << name << " was created" << RESET << std::endl;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard_gate_mode = false;
}

bool	ScavTrap::getGuardGate() const
{
	return (this->guard_gate_mode);
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << CYAN << "ScavTrap copy constructor called" << RESET << std::endl;
	this->guard_gate_mode = copy.getGuardGate();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		this->name = copy.getName();
		this->hit_points = copy.getHitPoints();
		this->attack_damage = copy.getAttackDamage();
		this->energy_points = copy.getEnergyPoints();
		this->guard_gate_mode = copy.getGuardGate();
	}
	std::cout << CYAN << "ScavTrap Assignation operator called" << RESET << std::endl;
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << CYAN << this->name << " ScavTrap was detroyed" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		this->energy_points--;
		std::cout << CYAN << "ScavTrap " << this->name << " attacks " << target
		<< " causing " << this->attack_damage << " points of damage!" << RESET << std::endl;
	}
	else if (this->energy_points == 0)
	{
		std::cout << CYAN << "ScavTrap " << this->name
		<< " cannot attack because it has no energy points." << RESET << std::endl;
	}
	else
	{
		std::cout << CYAN << "ScavTrap " << this->name
		<< " cannot attack because it is dead." << RESET << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (!this->guard_gate_mode)
	{
		guard_gate_mode = true;
		std::cout << CYAN << "ScavTrap " << this->name << " is now in Gatekeeper mode!" << RESET << std::endl;
	}
	else
	{
		guard_gate_mode = false;
		std::cout << CYAN << "ScavTrap " << this->name << " is no longer in Gatekeeper mode." << RESET << std::endl;
	}
}