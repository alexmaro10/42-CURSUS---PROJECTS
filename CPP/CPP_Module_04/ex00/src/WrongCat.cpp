/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 09:24:50 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/23 08:47:40 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << RED << "WrongCat Default Constructor Called." << RESET << std::endl;
	this->type = "WRONGCAT";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << RED << "WrongCat Copy Constructor Called." << RESET << std::endl;
	this->type = copy.type;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << RED << "Assigment Operator Called." << RESET << std::endl;
	if (this !=&copy)
	{
		this->type = copy.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat was destroyed" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << RED << this->getType() << ": *MUAI MUAI*" << RESET << std::endl;
}