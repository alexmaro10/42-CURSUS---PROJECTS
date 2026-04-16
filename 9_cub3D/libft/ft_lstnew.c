/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 18:05:49 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(1 * sizeof (t_list));
	if (!a)
		return (NULL);
	a -> content = content;
	a -> next = NULL;
	return (a);
}

/*int main(void)
{
    char *a = "hello";  // Cadena que se va a almacenar en el nodo
    t_list *node = ft_lstnew(a);  // Crea el nodo con el contenido

    if (node != NULL)
        printf("%s\n", (char *)node->content);

    // No olvides liberar la memoria
    free(node);

    return 0;
}*/

/*int	main(void)
{
	char	*a = "hello";
	
	printf("%s", (char *)(ft_lstnew(a) -> content));
	free(a);
	return (0);
}*/

/*int	main(void)
{
	char	*a = "hello";
	char	*b;
	int	i;
	
	i = 0;
	b = malloc(1 * sizeof (t_list));
	if (!b)
		return (NULL);
	while (i < (int)(strlen(ft_lstnew(a) -> content)))
	{
		b[i] = (char)(ft_lstnew(a) -> content[i]);
		i++;
	}
	b[i] = '\0';
	printf("%s", b);
	return (0);
}*/

/*t_list	*ft_lstnew(void *content)
{
	typedef struct s_list
	{
		void	*content;
		struct	s_list *next;
	}		t_list;

	t_list	*a;
	t_list	*b;
	a = malloc(1 * sizeof (t_list));
	if (!a)
		return (NULL);
	b = malloc(2 * sizeof (t_list));
	if (!b)
		return (NULL);
	b -> content = NULL;
	b -> next = NULL;
	a -> content = content;
	a -> next = NULL;
	
	b[0] = (t_list)NULL;
	b[1] = (t_list)NULL;
	a[0] = (t_list)content;
	a[1] = *b;
	return(a);
}*/

/*int	main(void)
{
	ft_lstnew(void *content)
	return (0);
}*/
