/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 18:05:49 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*current;

	new_lst = NULL;
	new_node = NULL;
	current = lst;
	if (!lst || !f)
		return (NULL);
	while (current)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
		{
			del(new_node);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		current = current->next;
	}
	return (new_lst);
}*/

/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new -> content = f(lst->content);
		if (!new)
		{
			del(new);
			return (NULL);
		}
		lst = lst->next;
		new = new -> next;
	}
	return (new);
}*/

/*t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(1 * sizeof (t_list));
	if (!a)
		return (NULL);
	a -> content = content;
	a -> next = NULL;
	return (a);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = NULL;
	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = *lst;
		del((*lst)-> content);
		*lst = temp -> next;
		free(temp);
	}
	*lst = NULL;
}*/

/*void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}*/

/*int main(void)
{
	char *a = "hello";
	char *b = "world";
	char *c = "!!!";
	char *c = "???";

	t_list *node1 = ft_lstnew(a);
	t_list *node2 = ft_lstnew(b);
	t_list *node3 = ft_lstnew(c);
	t_list *node4 = ft_lstnew(d);
	
	node1 -> next = node2;
	node2 -> next = node3;
	node3 -> next = node4;
	
	ft_lstclear(t_list **lst, ft_lstdelone);

	printf("%s\n", (char *)node1 -> content);

	free(node1);
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
