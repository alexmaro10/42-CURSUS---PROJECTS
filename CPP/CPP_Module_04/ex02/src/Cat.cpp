/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:48:39 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/23 08:49:35 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor Called." << RESET << std::endl;
	this->type = "CAT";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << GREEN << "Cat Copy Constructor Called." << RESET << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << GREEN << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		delete this->brain;
		this->brain = new Brain(*copy.brain);
		this->type = copy.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat was destroyed" << RESET << std::endl;
	delete this->brain;
}

void Cat::makeSound()  const
{
	std::cout << GREEN << this->getType() << ": *MIAU MIAU*" << RESET << std::endl;
}

std::string Cat::getIdea(size_t n) const
{
	return (this->brain->getIdea(n));
}

void	Cat::setIdea(size_t i, std::string idea)
{
	this->brain->setIdea(i, idea);
}