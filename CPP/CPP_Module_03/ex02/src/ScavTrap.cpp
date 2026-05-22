/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:03:20 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/02 10:51:24 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap was created" << std::endl;
	this->name = "S_Bot";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard_gate_mode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap named " << name << " was created" << std::endl;
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
	std::cout << "ScavTrap copy constructor called" << std::endl;
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
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	return(*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name << " ScavTrap was detroyed" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
		if (this->energy_points > 0)
	{
		energy_points--;
		std::cout << "ScavTrap " << this->name << " attacks " << target
		<< " causing " << this->attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name
		<< " cannot attack because it has no energy points." << std::endl;
}

void	ScavTrap::guardGate()
{
	guard_gate_mode = true;
	std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode!" << std::endl;
}