/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:16:58 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/23 08:46:28 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int	value;
		static const int n_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &fix);
		Fixed &operator=(const Fixed &fix);
		~Fixed(void);
		
		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif