/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:06:30 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/20 09:02:16 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Default Bureaucrat Contructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade <= 150 && grade >= 1)
	{
		std::cout << "Parametrized Bureaucrat Contructor called" << std::endl;
	}
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	std::cout << "Copy Bureaucrat Constructor called" << std::endl;
	this->grade = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy Assigment Bureaucrat Contructor called" << std::endl;
	if (this != &other)
	{
		this->grade = other.getGrade();
		return *this;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade > 1)
		grade--;
	else
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::decrementGrade()
{
	if (this->grade < 150)
		grade++;
	else
		throw(Bureaucrat::GradeTooLowException());
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (YELLOW "Exception:\n  Grade too high!" RESET);
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (YELLOW "Exception:\n  Grade too low!" RESET);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &a)
{
	return (o << a.getName() << ", bureaucrat grade " << a.getGrade() << ".");
}