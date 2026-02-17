/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:19:47 by almaldon          #+#    #+#             */
/*   Updated: 2026/01/19 10:19:47 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"
# include <iomanip>

class Phonebook
{
	private:
		Contacts contacts[8];
		int index;
		int n_contacts;
	
	public:
		Phonebook(void);
		void add(void);
		void search(void);
		void exit(void);
		int valid_arguments(std::string nam, std::string sn, std::string nic, std::string num, std::string ds);
		int filterIndex(std::string str);
};

#endif