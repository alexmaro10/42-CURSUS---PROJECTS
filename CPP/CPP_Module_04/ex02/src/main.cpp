/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:27:20 by almaldon          #+#    #+#             */
/*   Updated: 2026/03/23 09:10:22 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#define N_ANIMALS 6

int	main()
{
	{
		std::cout << "|------------------------------|" << std::endl;
		std::cout << "|                              |" << std::endl;
		std::cout << "|                              |" << std::endl;
		std::cout << "|" << BLUE <<"   ANIMAL INSTRUCTION COLOR   " << RESET << "|" << std::endl;
		std::cout << "|" << MAGENTA <<"     DOG INSTRUCTION COLOR    " << RESET << "|" << std::endl;
		std::cout << "|" << GREEN <<"     CAT INSTRUCTION COLOR    " << RESET << "|" << std::endl;
		std::cout << "|                              |" << std::endl;
		std::cout << "|                              |" << std::endl;
		std::cout << "|------------------------------|" << std::endl << std::endl;
	}
	
	{
		/*std::cout << "\033[33m" << "Animal class should not be instantiable\n"<< "\033[0m";
		Animal not_allowed;*/
	}
	
	std::cout << std::endl;

	{
		std::cout << "### ANIMAL ARRAY TESTS ###" << std::endl << std::endl;
		Animal* animal_arr[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i % 2 == 0)
				animal_arr[i] = new Dog();
			else
				animal_arr[i] = new Cat();
		}

		std::cout << std::endl;

		for (int i = 0; i < N_ANIMALS; i++)
		{
			animal_arr[i]->makeSound();
		}

		std::cout << std::endl;

		for (int i = 0; i < N_ANIMALS; i++)
		{
			delete animal_arr[i];
		}
	}

	std::cout << std::endl;

	{
		std::cout << "### DEEP COPY TEST ###" << std::endl << std::endl;
		Cat cat;
		Cat copy_cat(cat);
		
		std::cout << std::endl;

		std::cout << "Idea 10 from cat: " << cat.getIdea(10) << std::endl;
		cat.setIdea(10, "MOUSEEEEEE");
		std::cout << "Idea 10 from cat: " << cat.getIdea(10) << std::endl;

		std::cout << "Idea 10 from copy_cat: " << copy_cat.getIdea(10) << std::endl;

		std::cout << std::endl;
		
		Dog dog;
		Dog copy_dog(dog);
		
		std::cout << std::endl;

		std::cout << "Idea 10 from dog: " << dog.getIdea(10) << std::endl;
		dog.setIdea(10, "BAAAAAAAAALL");
		std::cout << "Idea 10 from dog: " << dog.getIdea(10) << std::endl;

		std::cout << "Idea 10 from copy_dog: " << copy_dog.getIdea(10) << std::endl;

		std::cout << std::endl;
	}
	
	std::cout << std::endl;


	{
		std::cout << "### DEEP ASSIGNMENT COPY TEST ###" << std::endl << std::endl;
		Dog dog;
		Dog assignment_dog(dog);
		std::cout << std::endl;
		
		std::cout << "Idea 10 from dog: " << dog.getIdea(10) << std::endl;
		dog.setIdea(10, "BAAAAAAAAALL");
		std::cout << "Idea 10 from dog: " << dog.getIdea(10) << std::endl;
		std::cout << std::endl;

		std::cout << "Idea 10 from assignment_dog before assignment: " << assignment_dog.getIdea(10) << std::endl;
		assignment_dog = dog;
		std::cout << "Idea 10 from assignment_dog after assignment: " << assignment_dog.getIdea(10) << std::endl;
		std::cout << std::endl;

		assignment_dog.setIdea(10, "RUUUUUUUN!");
		std::cout << "Idea 10 from assignment dog: " << assignment_dog.getIdea(10) << std::endl;
		std::cout << "Idea 10 from dog: " << dog.getIdea(10) << std::endl;

		std::cout << std::endl;
		
		Cat cat;
		Cat assignment_cat(cat);
		std::cout << std::endl;
		
		std::cout << "Idea 10 from cat: " << cat.getIdea(10) << std::endl;
		cat.setIdea(10, "MOUSEEEEEE");
		std::cout << "Idea 10 from cat: " << cat.getIdea(10) << std::endl;
		std::cout << std::endl;

		std::cout << "Idea 10 from assignment_cat before assignment: " << assignment_cat.getIdea(10) << std::endl;
		assignment_cat = cat;
		std::cout << "Idea 10 from assignment_cat after assignment: " << assignment_cat.getIdea(10) << std::endl;
		std::cout << std::endl;

		assignment_cat.setIdea(10, "RUUUUUUUN!");
		std::cout << "Idea 10 from assignment cat: " << assignment_cat.getIdea(10) << std::endl;
		std::cout << "Idea 10 from cat: " << cat.getIdea(10) << std::endl;

		std::cout << std::endl;
	}
	return 0;
}