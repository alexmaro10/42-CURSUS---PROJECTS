/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 09:05:24 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 17:14:33 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default PPF", 25, 5), target("null")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	this->target = other.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else
		beExecuted();
}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &a)
{
	return (o << a.getName() << " form, signed: " << a.getIsSigned() << ", sign grade: " << a.getGradeToSign() << ", exec grade: " << a.getGradeToExecute());
}