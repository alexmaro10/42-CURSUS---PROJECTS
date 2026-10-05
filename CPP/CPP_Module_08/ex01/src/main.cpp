/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:24:18 by almaldon          #+#    #+#             */
/*   Updated: 2026/06/02 12:34:52 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

#define MAX_VALUE 10

int main()
{
	Span sp = Span(MAX_VALUE);

	sp.addNumber(18);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(34);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		Span b = Span(3);
		b.addNumber(1);
		b.addNumber(1);
		b.addNumber(1);
		b.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Span b = Span(3);
		b.addNumber(1);
		std::cout << b.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Span b = Span(3);
		b.addNumber(1);
		std::cout << b.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}