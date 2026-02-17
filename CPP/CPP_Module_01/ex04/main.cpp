/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:01:19 by almaldon          #+#    #+#             */
/*   Updated: 2026/02/10 10:01:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Error:\nInvalid number of arguments (must be 3)"<< std::endl;
		return (1);
	}
	
	std::string line;
	std::string search = argv[2];
	if (search.empty())
	{
		std::cerr << "Error: search cannot be empty" << std::endl;
		return 1;
	}
	std::string replace = argv[3];
	std::string filename = argv[1];
	std::string newfilename = filename + ".replace";
	std::fstream file;
	int	i;
	int j;
	size_t count;
	file.open(argv[1]);
	if (!file)
	{
		std::cout << "Error:\nInvalid filename"<< std::endl;
		return (1);
	}
	std::ofstream newfile(newfilename.c_str());
	bool firstline = true;
	while (getline(file, line))
	{
		if (!firstline)
		newfile << '\n';
		firstline = false;
		i = 0;
		while (line[i])
		{
			if (line[i] == search[0])
			{
				j = 1;
				count = 1;
				while (search[j] && line[i + j] && line[i + j] == search[j])
				{
					count++;
					j++;
				}
				if (count == search.length())
				{
					newfile << replace;
					i = i + search.length();
				}
				else
				{
					newfile << line[i];
					i++;
				}
			}
			else
			{
				newfile << line[i];
				i++;
			}
		}
	}
	file.close();
	newfile.close();

	std::cout << "File " << newfilename << " was created!" << std::endl;
	return (0);
}