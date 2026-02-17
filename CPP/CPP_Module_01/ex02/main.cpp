/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:00:37 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 09:31:28 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string text = "HI THIS IS BRAIN";
	std::string *stringPTR = &text;
	std::string &stringREF = text;

	std::cout << "Memory position: " << &text << std::endl;
	std::cout << "Memory position: " << stringPTR << std::endl;
	std::cout << "Memory position: " << &stringREF << std::endl << std::endl;
	
	std::cout << "Value: " << text << std::endl;
	std::cout << "Value: " << *stringPTR << std::endl;
	std::cout << "Value: " << stringREF << std::endl;

	return (0);
}