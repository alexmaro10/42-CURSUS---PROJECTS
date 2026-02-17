/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:19:34 by almaldon          #+#    #+#             */
/*   Updated: 2026/01/19 10:19:34 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <string>

class Contacts
{
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string number;
		std::string darkest_secret;
	
	public:
		Contacts();
		Contacts(std::string nam, std::string sn, std::string num);
		std::string getName();
		std::string getSurname();
		std::string getNumber();
		std::string getNickname();
		std::string getDarkestSecret();
		void setName(std::string nam);
		void setSurname(std::string sn);
		void setNumber(std::string num);
		void setNickname(std::string nic);
		void setDarkestSecret(std::string ds);
};

#endif