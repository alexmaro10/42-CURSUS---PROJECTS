/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:05:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/23 08:46:22 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
#include <cmath>

class Fixed
{
	private:
		int value;
		static const int n_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed& operator=(const Fixed& fix);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		//ex01
		Fixed(const int raw);
		Fixed(const float raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif