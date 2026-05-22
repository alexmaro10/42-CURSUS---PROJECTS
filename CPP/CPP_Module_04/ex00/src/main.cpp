/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:27:20 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/09 09:37:38 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int	main()
{
	std::cout << "|------------------------------|" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|" << BLUE <<"   ANIMAL INSTRUCTION COLOR   " << RESET << "|" << std::endl;
	std::cout << "|" << MAGENTA <<"     DOG INSTRUCTION COLOR    " << RESET << "|" << std::endl;
	std::cout << "|" << GREEN <<"     CAT INSTRUCTION COLOR    " << RESET << "|" << std::endl;
	std::cout << "|" << YELLOW <<"WRONG ANIMAL INSTRUCTION COLOR" << RESET << "|" << std::endl;
	std::cout << "|" << RED <<"  WRONG CAT INSTRUCTION COLOR " << RESET << "|" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|------------------------------|" << std::endl << std::endl;

	std::cout << "######### ANIMAL TEST #########" << std::endl << std::endl;
	std::cout << "--------- Constructors --------" << std::endl << std::endl;
	Animal a1;
	Animal a2(a1);
	Animal a3;
	
	a3 = a2;
	
	std::cout << std::endl << "--------- Make Sound --------" << std::endl << std::endl;
	a3.makeSound();

	std::cout << std::endl << "######### DOG TEST #########" << std::endl << std::endl;
	std::cout << "--------- Constructors --------" << std::endl << std::endl;
	Animal *d1 = new Dog();
	Animal *d2 = new Dog(*static_cast<Dog*>(d1));
	Animal *d3 = new Dog();
	
	*d3 = *d2;
	
	std::cout << std::endl << "--------- Make Sound --------" << std::endl << std::endl;
	d2->makeSound();
	d3->makeSound();

	std::cout << std::endl << "######### CAT TEST #########" << std::endl << std::endl;
	std::cout << "--------- Constructors --------" << std::endl << std::endl;
	Animal *c1 = new Cat();
	Animal *c2 = new Cat(*static_cast<Cat*>(c1));
	Animal *c3 = new Cat();
	
	*c3 = *c2;
	
	std::cout << std::endl << "--------- Make Sound --------" << std::endl << std::endl;
	c2->makeSound();
	c3->makeSound();

	std::cout << std::endl << "######### WRONG ANIMAL TEST #########" << std::endl << std::endl;
	std::cout << "--------- Constructors --------" << std::endl << std::endl;
	WrongAnimal wa1;
	WrongAnimal wa2(wa1);
	WrongAnimal wa3;
	
	wa3 = wa2;
	
	std::cout << std::endl << "--------- Make Sound --------" << std::endl << std::endl;
	wa2.makeSound();
	wa3.makeSound();

	std::cout << std::endl << "######### WRONG CAT TEST #########" << std::endl << std::endl;
	std::cout << "--------- Constructors --------" << std::endl << std::endl;
	WrongAnimal *wc1 = new WrongCat();
	WrongAnimal *wc2 = new WrongCat(*static_cast<WrongCat*>(wc1));
	WrongAnimal *wc3 = new WrongCat();
	
	*wc3 = *wc2;
	
	std::cout << std::endl << "--------- Make Sound --------" << std::endl << std::endl;
	wc2->makeSound();
	wc3->makeSound();

	std::cout << std::endl << "####### DESTRUCTORS #######" << std::endl << std::endl;
	delete d1;
	delete d2;
	delete d3;
	delete c1;
	delete c2;
	delete c3;
	delete wc1;
	delete wc2;
	delete wc3;
	
}