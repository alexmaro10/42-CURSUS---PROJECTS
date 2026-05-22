/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:05:02 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/23 10:58:09 by almaldon         ###   ########.fr       */
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
		int					value;
		static const int	n_bits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& fix);
		Fixed&				operator=(const Fixed& fix);
		~Fixed(void);
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		//ex01
		Fixed(const int raw);
		Fixed(const float raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		//ex02
		bool				operator>(Fixed fixed)const;
		bool				operator<(Fixed fixed)const;
		bool				operator>=(Fixed fixed)const;
		bool				operator<=(Fixed fixed)const;
		bool				operator==(Fixed fixed)const;
		bool				operator!=(Fixed fixed)const;
		float				operator+(Fixed fixed)const;
		float				operator-(Fixed fixed)const;
		float				operator*(Fixed fixed)const;
		float				operator/(Fixed fixed)const;
		Fixed				operator++();
		Fixed				operator--();
		Fixed				operator++(int n);
		Fixed				operator--(int n);
		static Fixed		&min(Fixed &first, Fixed &second);
		static const Fixed	&min(Fixed const &first, Fixed const &second);
		static Fixed		&max(Fixed &first, Fixed &second);
		static const Fixed	&max(Fixed const &first, const Fixed &second);
};

std::ostream				&operator<<(std::ostream &o, Fixed const &fixed);

#endif