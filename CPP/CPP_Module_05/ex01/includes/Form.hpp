/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:38:58 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/13 10:45:10 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;

	public:
		Form();
		Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned();

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

std::ostream	&operator<<(std::ostream &o, Form const &a);