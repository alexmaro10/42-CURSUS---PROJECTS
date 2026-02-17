/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_built_in_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 12:24:04 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_n(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
}

void	ft_echo(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("%s", str[i]);
		if (str[i + 1])
			printf(" ");
		i++;
	}
	printf("\n");
}

void	ft_pwd(void)
{
	char	*cwd;
	int		i;

	i = 0;
	cwd = getcwd(NULL, 0);
	if (!cwd)
		perror("getcwd");
	else
	{
		printf("%s\n", cwd);
		free(cwd);
	}
}

void	ft_env(char **copy_env)
{
	int	i;

	i = 0;
	while (copy_env && copy_env[i])
	{
		if (ft_strchr(copy_env[i], '='))
			printf("%s\n", copy_env[i]);
		i++;
	}
}
