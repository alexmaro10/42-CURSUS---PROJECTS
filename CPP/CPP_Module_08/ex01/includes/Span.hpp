/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:59:55 by almaldon          #+#    #+#             */
/*   Updated: 2026/06/02 12:14:08 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
		unsigned int N;
		std::vector<int> v;

	public:
		Span();
		Span(int n);
		Span(const Span& other);
		Span &operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		class FullContainerException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};