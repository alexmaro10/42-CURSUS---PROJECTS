/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:49:14 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 16:13:18 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : name("Default Form"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute)
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Form::GradeTooLowException());
	else if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else
	{
		this->is_signed = false;
		std::cout << "Parametrized Form Constructor Called" << std::endl;
	}
}

Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << "Copy Form Constructor Called" << std::endl;
}

Form &Form::operator=(const Form& other)
{
	std::cout << "Copy Assigment Form Called" << std::endl;
	if (this == &other)
		return *this;
	this->is_signed = other.is_signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor Called" << std::endl;
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

int Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

void Form::beSigned()
{
	if (this->is_signed == true)
		std::cout << "Can't sign " << this->name << " Form because is already signed" << std::endl;
	else
		std::cout << this->name << " Form has been signed" << std::endl;
	is_signed = true;
}

char const *Form::GradeTooHighException::what() const throw()
{
	return (MAGENTA "Exception:\n  Grade too high!" RESET);
}

char const *Form::GradeTooLowException::what() const throw()
{
	return (MAGENTA "Exception:\n  Grade too low!" RESET);
}

std::ostream &operator<<(std::ostream &o, Form const &a)
{
	if (a.getIsSigned() == 1)
	{
		return (o << "Form " << a.getName() << ", is signed? YES"
			<< "\nGrade to sign: " << a.getGradeToSign() << "\nGrade to execute: " << a.getGradeToExecute()
			<< std::endl);
	}
	else
	{
		return (o << "Form " << a.getName() << ", is signed? NO"
			<< "\nGrade to sign: " << a.getGradeToSign() << "\nGrade to execute: " << a.getGradeToExecute()
			<< std::endl);
	}
}