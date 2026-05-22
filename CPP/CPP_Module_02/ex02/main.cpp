/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:42:15 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/26 09:20:09 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(5);
	Fixed b(Fixed(5.25f) * Fixed(2));
	
	std::cout << "####### comparison operators #######" << std::endl << std::endl;
	std::cout << "operator<: " << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << "operator<=: " << a << " <= " << b << ": " << (a <= b) << std::endl;
	std::cout << "operator>: " << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << "operator>=: " << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << "operator==: " << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << "operator!=: " << a << " != " << b << ": " << (a != b) << std::endl;

	std::cout << std::endl << "####### Aritmetic operators #######" << std::endl << std::endl;
	std::cout << "operator+: " << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << "operator-: " << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << "operator*: " << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << "operator/: " << a << " / " << b << " = " << (a / b) << std::endl;

	std::cout << std::endl << "####### Increment and Decrement operators #######" << std::endl << std::endl;
	std::cout << "operator++(void) (++a): " << (++a) << std::endl;
	std::cout << "operator++(int) (a++): " << (a++) << " --> " << a << std::endl;
	std::cout << "operator--(void) (--a): " << (--a) << std::endl;
	std::cout << "operator++(int) (a--): " << (a--) << " --> " << a << std::endl;

	std::cout << std::endl << "####### Min and Max operators #######" << std::endl << std::endl;
	std::cout << "operator min(Fixed &first, Fixed &second): " << Fixed::min(a, b) << std::endl;
	std::cout << "operator max(Fixed &first, Fixed &second): " << Fixed::max(a, b) << std::endl;
	a.setRawBits(84 * 256);
	std::cout << a << std::endl;
	const Fixed c(a);
	const Fixed d(b);
	std::cout << "operator const min(const Fixed &first, const Fixed &second): " << Fixed::min(c, d) << std::endl;
	std::cout << "operator const max(const Fixed &first, const Fixed &second): " << Fixed::max(c, d) << std::endl;
	
	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl;
	return 0;
}