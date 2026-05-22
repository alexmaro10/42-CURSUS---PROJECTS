/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:18:08 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/26 09:09:37 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default Contructor Called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int Contructor Called" << std::endl;
	this->value = raw << this->n_bits;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float Contructor Called" << std::endl;
	this->value = roundf(raw * (1 << this->n_bits));
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy Contructor Called" << std::endl;
	this->value = fix.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fix)
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

float Fixed::toFloat(void) const
{
	return ((float)(this->value) / (1<<this->n_bits));
}

int Fixed::toInt() const
{
	return ((this->value + (1 << (this->n_bits - 1))) >> this->n_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}