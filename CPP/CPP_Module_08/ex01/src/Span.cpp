/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:05:12 by almaldon          #+#    #+#             */
/*   Updated: 2026/06/02 12:35:34 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span()
{
	this->N = 0;
}

Span::Span(int n)
{
	this->N = n;
}

Span::Span(const Span& other)
{
	*this = other;
}

Span &Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->v = other.v;
		this->N = other.N;
	}
	return (*this);
}

Span::~Span()
{
	
}

void Span::addNumber(int n)
{
	if (this->v.size() < N)
		this->v.push_back(n);
	else
	{
		throw(Span::FullContainerException());
	}
}

int Span::longestSpan()
{
	int st;
	int lg = 0;
	
	if (this->v.size() <= 1)
		throw(Span::NotEnoughNumbersException());
	
	for (size_t i = 0; i < this->v.size(); i++)
	{
		if (this->v[i] > lg)
			lg = this->v[i];
	}

	st = lg;

	for (size_t i = 0; i < this->v.size(); i++)
	{
		if (this->v[i] < st)
			st = this->v[i];
	}
	
	return (lg - st);
}

int Span::shortestSpan()
{
	int sp;
	int lg = 0;
	
	if (this->v.size() <= 1)
		throw(Span::NotEnoughNumbersException());
	
	for (size_t i = 0; i < this->v.size(); i++)
	{
		if (this->v[i] > lg)
			lg = this->v[i];
	}

	sp = lg;

	for (size_t i = 0; i < this->v.size(); i++)
	{
		for (size_t j = i + 1; j < this->v.size(); j++)
		{
			if (abs(this->v[i] - this->v[j]) < sp)
				sp = abs(this->v[i] - this->v[j]);
		}
	}

	return (sp);
}

const char* Span::FullContainerException::what() const throw()
{
    return "Exception\nContainer is full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
    return "Exception\nNot enough numbers";
}