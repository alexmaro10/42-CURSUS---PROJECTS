/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:59:01 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/26 10:34:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	killing_func(int pid, unsigned char octet)
{
	int				i;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	i = 8;
	while (i-- > 0)
	{
		octet_tmp = octet >> i;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		client_id;
	char	*str_to_send;
	int		i;

	if (argc != 3)
	{
		ft_printf("Los parametros recibidos no son correctos\n");
		return (0);
	}
	client_id = ft_atoi(argv[1]);
	str_to_send = ft_strjoin(argv[2], "\n");
	i = 0;
	while (str_to_send[i])
	{
		killing_func(client_id, (unsigned char)str_to_send[i]);
		i++;
	}
	free(str_to_send);
	return (0);
}
