/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:19:13 by almaldon          #+#    #+#             */
/*   Updated: 2026/01/19 10:19:16 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	std::string message;
	int	i;
	int j;

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	i=0;
	while (argv[++i]) {
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
			{
				message += toupper(argv[i][j]);
			}
			else
			{
				message += argv[i][j];
			}
		}
	}
	std::cout << message;
	return (0);
}