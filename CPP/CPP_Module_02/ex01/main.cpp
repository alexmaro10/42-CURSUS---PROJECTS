/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:42:15 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/26 09:12:14 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "####### CONSTRCTORS #######" << std::endl << std::endl;
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 5.25f );
	Fixed const d( b );
	
	a = Fixed( 12.25f );
	
	std::cout << std::endl << "####### toFloat Function #######" << std::endl << std::endl;
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << std::endl << "####### toInt Function #######" << std::endl << std::endl;
		
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl << std::endl;
	return (0);
}