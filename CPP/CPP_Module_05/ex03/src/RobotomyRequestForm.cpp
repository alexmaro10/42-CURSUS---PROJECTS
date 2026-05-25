/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 08:41:35 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 17:18:41 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default RRF", 72, 45), target("null")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	this->target = other.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else
		beExecuted();
}

void RobotomyRequestForm::beExecuted() const
{
	std::srand(std::time(0));

	int numero = std::rand() % 2 + 1;
	
	if (numero == 2)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << this->target << " has been NOT robotomized" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &a)
{
	return (o << a.getName() << " form, signed: " << a.getIsSigned() << ", sign grade: " << a.getGradeToSign() << ", exec grade: " << a.getGradeToExecute());
}
