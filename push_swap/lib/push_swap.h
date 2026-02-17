/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:37:35 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/15 10:40:12 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	char			*value;
	int				index;
	struct s_list	*next;
}		t_list;

int		isdgt(int c);
int		ft_isspace(int c);
int		ft_issign(int c);
int		ft_isalpha(int c);
int		ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
char	**ft_split_multiple(char **args, int argc, char c);
int		fill_word(char *word, char const *s, char c);
int		len_word(char const *s, char c);
int		count_words(char const *s, char c);
int		control_total(char **argv, char **nbrs);
void	free_lst(t_list **lst);
void	free_nbrs(char **nbrs);
t_list	*ft_lstnew(char *nbr);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	assig_sort_index(t_list *lst);
void	sort_2_arg(t_list **lst);
void	sort_3_arg(t_list **lst);
void	sort_4_arg(t_list **lst_a, t_list **lst_b);
void	sort_5_arg(t_list **lst_a, t_list **lst_b);
void	swap_a(t_list **head);
void	swap_b(t_list **head);
void	swap_ab(t_list **list_a, t_list **list_b);
void	push_a(t_list **list_a, t_list **list_b);
void	push_b(t_list **list_a, t_list **list_b);
void	rotate_a(t_list **head);
void	rotate_b(t_list **head);
void	rotate_ab(t_list **list_a, t_list **list_b);
void	r_rotate_a(t_list **head);
void	r_rotate_b(t_list **head);
void	r_rotate_ab(t_list **list_a, t_list **list_b);
int		is_sorted(t_list *lst);
int		find_bits(int biggest_nbr);
void	chunk_sort(t_list **lst_a, t_list **lst_b, int total_elements);
int		get_position(t_list *stack, int val);

#endif