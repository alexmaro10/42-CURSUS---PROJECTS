/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:16:05 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/23 08:48:26 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	std::cout << BLUE << "Animal Default Constructor Called." << RESET << std::endl;
	this->type = "ANIMAL";
}

Animal::Animal(const Animal &copy)
{
	std::cout << BLUE << "Animal Copy Constructor Called." << RESET << std::endl;
	this->type = copy.type;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << BLUE << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal was destroyed" << RESET << std::endl;
}

void Animal::makeSound() const
{
	std::cout << BLUE << this->type << ": *ANIMAL SOUND*" << RESET << std::endl;
}