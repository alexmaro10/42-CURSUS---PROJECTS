/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:38:58 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 16:00:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const		std::string name;
		bool		is_signed;
		const int	grade_to_sign;
		const int	grade_to_execute;

	public:
		AForm();
		AForm(const std::string name, const int grade_to_sign, const int grade_to_execute);
		AForm(const AForm& other);
		AForm &operator=(const AForm& other);
		virtual ~AForm();

		const std::string	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned();
		virtual void		beExecuted() const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
		

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
	
		class FormNotSignedException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};

};

std::ostream	&operator<<(std::ostream &o, AForm const &a);