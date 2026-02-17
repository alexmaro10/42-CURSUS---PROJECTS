/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:14:08 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/09 10:31:51 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &wp;
	public:
		HumanA(std::string name, Weapon &wp);
		~HumanA();
		void attack(void);
};