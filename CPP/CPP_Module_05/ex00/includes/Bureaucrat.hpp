/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:47:50 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/13 11:52:23 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define YELLOW  "\x1b[33m"
#define MAGENTA "\x1b[35m"
#define GREEN   "\x1b[32m"
#define BIGGREEN   "\x1b[1;32m"
#define CYAN    "\x1b[36m"
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();	
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &a);