/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:06:33 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/09 10:48:41 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon();
		std::string getType(void) const;
		void	setType(std::string type);
};