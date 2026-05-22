/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:42:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/19 19:19:45 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << MAGENTA << "Dog Default Constructor Called." << RESET << std::endl;
	this->type = "DOG";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << MAGENTA << "Dog Copy Constructor Called." << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << MAGENTA << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog was destroyed" << RESET << std::endl;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << this->getType() << ": *GUAU GUAU*" << RESET << std::endl;
}