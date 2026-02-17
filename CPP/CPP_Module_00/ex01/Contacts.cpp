/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:19:29 by almaldon          #+#    #+#             */
/*   Updated: 2026/01/19 10:19:29 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contacts.hpp"

Contacts::Contacts()
{
	name = " ";
	surname = " ";
	number = " ";
}

Contacts::Contacts(std::string name, std::string surname, std::string number)
{
	this->name = name;
	this->surname = surname;
	this->number = number;
}

std::string Contacts::getName()
{
	return (name);
}

std::string Contacts::getSurname()
{
	return (surname);
}

std::string Contacts::getNumber()
{
	return (number);
}

std::string Contacts::getNickname()
{
	return (nickname);
}

std::string Contacts::getDarkestSecret()
{
	return (darkest_secret);
}

void Contacts::setName(std::string name)
{
	this->name = name;
}

void Contacts::setSurname(std::string surname)
{
	this->surname = surname;
}

void Contacts::setNumber(std::string number)
{
	this->number = number;
}

void Contacts::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contacts::setDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}