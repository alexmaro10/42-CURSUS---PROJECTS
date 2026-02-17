/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:19:43 by almaldon          #+#    #+#             */
/*   Updated: 2026/01/19 10:19:43 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	index = 0;
	n_contacts = 0;
}

void Phonebook::exit(void)
{
	std::cout << std::endl << "¡SEE YOU SOON!" << std::endl << std::endl;
}

int Phonebook::valid_arguments(std::string nam, std::string sn, std::string nic, std::string num, std::string ds)
{
	int res[5] = {0, 0, 0, 0, 0};

	if (nam.length() == 0 || !isalpha(nam[0]))
		res[0] = 1;
	for (size_t i = 0; i < nam.length(); i++)
	{
		if (!isalpha(nam[i]) && nam[i] != ' ')
			res[0] = 1;
	}
	if (sn.length() == 0 || !isalpha(sn[0]))
		res[1] = 1;
	for (size_t i = 0; i < sn.length(); i++)
	{
		if (!isalpha(sn[i]) && sn[i] != ' ')
			res[1] = 1;
	}
	if (nic.length() == 0 || isspace(nic[0]))
		res[2] = 1;
	for (size_t i = 0; i < nic.length(); i++)
	{
		if (!isascii(nic[i]))
			res[2] = 1;
	}
	if (num.length() == 0 || !isdigit(num[0]))
		res[3] = 1;
	for (size_t i = 0; i < num.length(); i++)
	{
		if (!isdigit(num[i]))
			res[3] = 1;
	}
	if (ds.length() == 0 || isspace(ds[0]))
		res[4] = 1;
	for (size_t i = 0; i < ds.length(); i++)
	{
		if (!isascii(ds[i]))
			res[4] = 1;
	}
	if (res[0] == 1)
		std::cout << "Invalid NAME" << std::endl << std::endl;
	if (res[1] == 1)
		std::cout << "Invalid LAST NAME" << std::endl << std::endl;
	if (res[2] == 1)
		std::cout << "Invalid NICKNAME" << std::endl << std::endl;
	if (res[3] == 1)
		std::cout << "Invalid NUMBER" << std::endl << std::endl;
	if (res[4] == 1)
		std::cout << "Invalid DARKEST SECRET" << std::endl << std::endl;
	if (res[0] == 1 || res[1] == 1 || res[2] == 1 || res[3] == 1 || res[4] == 1)
		return (1);
	return (0);
}

void Phonebook::add()
{
	int valid;
	int	refill;

	refill = 0;
	if (n_contacts == 8)
	{
		if (index == 8)
			index = 0;
		n_contacts = 7;
		refill = 1;
	}
	std::string nam, sn, nic, num, ds;
	std::cout << "NAME: ";
	std::getline(std::cin, nam);
	std::cout << "LAST NAME: ";
	std::getline(std::cin, sn);
	std::cout << "NICKNAME: ";
	std::getline(std::cin, nic);
	std::cout << "NUMBER: ";
	std::getline(std::cin, num);
	std::cout << "DARKEST SECRET: ";
	std::getline(std::cin, ds);
	valid = valid_arguments(nam, sn, nic, num, ds);
	if (valid == 0)
	{
		contacts[index].setName(nam);
		contacts[index].setSurname(sn);
		contacts[index].setNickname(nic);
		contacts[index].setNumber(num);
		contacts[index].setDarkestSecret(ds);
		index++;
		n_contacts++;
		std::cout << std::endl << "NEW CONTACT ADDED!" << std::endl << std::endl;
	}
	else
	{
		if (refill == 1)
		{
			index = 8;
			n_contacts = 8;
		}
	}
}


int Phonebook::filterIndex(std::string str)
{
	int value = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			value = 42;
			break ;
		}
		value = (value * 10) + (str[i] - '0');
	}
	return value;
}

void Phonebook::search()
{
	std::string	input;
	int			n_input;

	if (n_contacts == 0)
	{
		std::cout << std::endl << "The phonebook is empty..." << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl <<"LIST OF CONTACTS" << std::endl << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|     INDEX|      NAME| LAST NAME|  NICKNAME|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;

		for (int i = 0; i < n_contacts; i++)
		{
			std::cout << "|"
					<< std::setw(10) << std::right << (i + 1)
					<< "|";
			if (contacts[i].getName().length() > 10)
				std::cout << std::setw(9) << std::right << contacts[i].getName().substr(0, 9) << "." << "|";
			else
				std::cout << std::setw(10) << contacts[i].getName() << "|";
			if (contacts[i].getSurname().length() > 10)
				std::cout << std::setw(9) << std::right << contacts[i].getSurname().substr(0, 9) << "." << "|";
			else
				std::cout << std::setw(10) << contacts[i].getSurname() << "|";
			if (contacts[i].getNickname().length() > 10)
				std::cout << std::setw(9) << std::right << contacts[i].getNickname().substr(0, 9) << "." << "|";
			else
				std::cout << std::setw(10) << contacts[i].getNickname() << "|";
			std::cout << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
		std::cout << std::endl << "Write an index: ";
		std::getline(std::cin, input);
		std::cout << std::endl;
		n_input = filterIndex(input);
		if (n_input > 9 || n_input < 0)
		{
			std::cout << "Contact not found!" << std::endl << std::endl;
		}
		else
		{
			for (int i = 0; i < n_contacts; i++)
			{
				if ((input[0] - '0') == i + 1)
				{
					std::cout << "NAME:\t\t" << contacts[i].getName() << std::endl;
					std::cout << "SURNAME:\t" << contacts[i].getSurname() << std::endl;
					std::cout << "NICKNAME:\t" << contacts[i].getNickname() << std::endl;
					std::cout << "NUMBER:\t\t" << contacts[i].getNumber() << std::endl; 
					std::cout << "DARKEST SECRET:\t" << contacts[i].getDarkestSecret() << std::endl << std::endl;
					break ;
				}
				if (i == n_contacts - 1)
					std::cout << "Contact not found!" << std::endl << std::endl;
			}
		}
	}
}
