/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:18:27 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/09 10:32:19 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *wp;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &wp);
		void attack(void);
};