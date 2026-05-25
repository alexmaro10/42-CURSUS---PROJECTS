/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 08:50:15 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/16 09:28:02 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{

};

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern& other)
{
	if (this == &other)
		return(*this);
	return (*this);
}

Intern::~Intern()
{
	
}

static std::string ft_toLower(std::string name)
{
	for (std::size_t i = 0; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}
	return (name);
}

static AForm *makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) =
	{
		&makePresidentialPardonForm,
		&makeRobotomyRequestForm,
		&makeShrubberyCreationForm
	};
	std::string forms[] =
	{
		"presidentialpardon",
		"robotomyrequest",
		"shrubberycreation"
	};
	std::string lower_name = name;

	lower_name = ft_toLower(lower_name);
	for (size_t i = 0; i < 3; i++)
	{
		if (lower_name == forms[i])
			return(all_forms[i](target));
	}
	std::cout << RED << "ERROR:\nName form no recognised." << RESET << std::endl; 
	return (NULL);
}