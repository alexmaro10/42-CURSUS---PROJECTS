/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:49:14 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 16:03:59 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : name("Default AForm"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Default AForm Constructor Called" << std::endl;
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute)
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->is_signed = false;
		std::cout << "Parametrized AForm Constructor Called" << std::endl;
	}
}

AForm::AForm(const AForm& other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << "Copy AForm Constructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm& other)
{
	std::cout << "Copy Assigment AForm Called" << std::endl;
	if (this == &other)
		return *this;
	this->is_signed = other.is_signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor Called" << std::endl;
}

const std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

int AForm::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int AForm::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

void AForm::beSigned()
{
	if (this->is_signed == true)
		std::cout << "Can't sign " << this->name << " AForm because is already signed" << std::endl;
	else
		std::cout << this->name << " AForm has been signed" << std::endl;
	is_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
}

void AForm::beExecuted() const
{
	
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return (MAGENTA "Exception:\n  Grade too high!" RESET);
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return (MAGENTA "Exception:\n  Grade too low!" RESET);
}

char const *AForm::FormNotSignedException::what() const throw()
{
	return (MAGENTA "Exception:\n Form is not signed" RESET);
}

std::ostream &operator<<(std::ostream &o, AForm const &a)
{
	if (a.getIsSigned() == 1)
	{
		return (o << "AForm " << a.getName() << ", is signed? YES"
			<< "\nGrade to sign: " << a.getGradeToSign() << "\nGrade to execute: " << a.getGradeToExecute()
			<< std::endl);
	}
	else
	{
		return (o << "AForm " << a.getName() << ", is signed? NO"
			<< "\nGrade to sign: " << a.getGradeToSign() << "\nGrade to execute: " << a.getGradeToExecute()
			<< std::endl);
	}
}