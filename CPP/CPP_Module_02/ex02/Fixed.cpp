/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:18:08 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/26 09:21:28 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
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
	this->value = fix.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fix)
{
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
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->value) / (1<<this->n_bits));
}

int	Fixed::toInt() const
{
	return ((this->value + (1 << (this->n_bits - 1))) >> this->n_bits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

//ex02

bool Fixed::operator<(Fixed fixed) const
{
	return(this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>(Fixed fixed) const
{
	return(this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
	return(this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
	return(this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
	return(this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
	return(this->toFloat() != fixed.toFloat());
}

float Fixed::operator+(const Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(const Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(const Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(const Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	++this->value;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--this->value;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}