/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:21:47 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/23 08:49:45 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << YELLOW << "WrongAnimal Default Constructor Called." << RESET << std::endl;
	this->type = "WRONGANIMAL";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << YELLOW << "WrongAnimal Copy Constructor Called." << RESET << std::endl;
	this->type = copy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << YELLOW << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << YELLOW << "WrongAnimal was destroyed" << RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << YELLOW << this->type << ": *WRONG ANIMAL SOUND*" << RESET << std::endl;
}