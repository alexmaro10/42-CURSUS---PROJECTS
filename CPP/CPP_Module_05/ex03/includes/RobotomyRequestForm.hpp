/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 08:25:19 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/28 15:59:13 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void beExecuted() const;
		void		execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &a);