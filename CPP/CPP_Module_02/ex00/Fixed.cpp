/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:17:01 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/23 08:43:39 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default Contructor Called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy Contructor Called" << std::endl;
	this->value = fix.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fix)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &fix)
		this->value = fix.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits Member Function Called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits Member Function Called" << std::endl;
	this->value = raw;
}