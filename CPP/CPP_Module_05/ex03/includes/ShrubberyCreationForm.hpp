/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 08:25:22 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 15:59:16 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <sstream>
#include <sys/stat.h>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string getTarget() const;
		void beExecuted() const;
		void		execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm const &a);