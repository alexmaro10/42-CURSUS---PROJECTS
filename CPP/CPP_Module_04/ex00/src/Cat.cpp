/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:48:39 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/19 19:19:36 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Cat Default Constructor Called." << RESET << std::endl;
	this->type = "CAT";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << GREEN << "Cat Copy Constructor Called." << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << GREEN << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << GREEN << "Cat was destroyed" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << GREEN << this->getType() << ": *MIAU MIAU*" << RESET << std::endl;
}