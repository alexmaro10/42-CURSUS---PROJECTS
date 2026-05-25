/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 09:01:10 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 16:17:58 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF Default", 145, 137), target("null")
{
	std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), target(target)
{
	std::cout << "Parametrized ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm::AForm(other), target(other.target)
{
	std::cout << "Copy ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Copy Assigment ShrubberyCreationForm Called" << std::endl;
	AForm::operator=(other);
	this->target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute() || executor.getGrade() > this->getGradeToSign())
		throw (AForm::GradeTooLowException());
	else if (!this->getIsSigned())
		throw (AForm::FormNotSignedException());
	else
		beExecuted();
}

void ShrubberyCreationForm::beExecuted() const
{
	std::ofstream outFile((target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";

		outFile.close();
	}
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &a)
{
	return (o << a.getName() << " form, signed: " << a.getIsSigned() << ", sign grade: " << a.getGradeToSign() << ", exec grade: " << a.getGradeToExecute());
}
