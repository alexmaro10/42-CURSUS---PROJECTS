/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:55:53 by almaldon          #+#    #+#             */
/*   Updated: 2026/06/03 09:24:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stack.pop() ~ elimina el elemento de encima
//stack.push() ~ añade un elemento y lo coloca al principio
//stack.top() ~ devuelve una referencia al primer elemento
//stack.empty() ~ comprueba si esta vacia
//stcak.size() ~ devuelve el numero de elementos

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();

		iterator begin();
		iterator end();

		const_iterator begin() const;
		const_iterator end() const;
		
};