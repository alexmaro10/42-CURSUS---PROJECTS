/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:42:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/23 08:49:39 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << MAGENTA << "Dog Default Constructor Called." << RESET << std::endl;
	this->type = "DOG";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << MAGENTA << "Dog Copy Constructor Called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << MAGENTA << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		delete this->brain;
		this->brain = new Brain(*(copy.brain));
		this->type = copy.type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << MAGENTA << "Dog was destroyed" << RESET << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << MAGENTA << this->getType() << ": *GUAU GUAU*" << RESET << std::endl;
}

std::string Dog::getIdea(size_t n) const
{
	return (this->brain->getIdea(n));
}

void	Dog::setIdea(size_t i, std::string idea)
{
	this->brain->setIdea(i, idea);
}