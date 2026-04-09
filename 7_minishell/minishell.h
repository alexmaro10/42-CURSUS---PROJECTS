/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 11:45:35 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <inttypes.h>
# include <stdbool.h> 
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "./libft/libft.h"

# define RESET				"\033[0m"
# define BLACK				"\033[0;30m"
# define RED				"\033[0;31m"
# define GREEN				"\033[1;32m"
# define YELLOW				"\033[0;33m"
# define BLUE				"\033[0;34m"
# define MAGENTA			"\033[0;35m"
# define CYAN				"\033[1;36m"
# define WHITE				"\033[0;37m"
# define BRIGHT_BLACK		"\033[1;30m"
# define BRIGHT_RED			"\033[1;31m"
# define BRIGHT_GREEN		"\033[1;32m"
# define BRIGHT_YELLOW		"\033[1;33m"
# define BRIGHT_BLUE		"\033[1;34m"
# define BRIGHT_MAGENTA		"\033[1;35m"
# define BRIGHT_CYAN		"\033[1;36m"
# define MAX_ARGS 64
# define MAX_REDIRS 16
# define REDIR_IN 0
# define REDIR_OUT 1
# define REDIR_APP 2
# define REDIR_HEREDOC 3

extern int	g_exit_status;

typedef struct s_quotes
{
	int		start;
	int		end;
	char	**token;
	char	quotes[2];
}	t_quotes;

typedef struct s_redirect
{
	int		type;
	char	*file;
}	t_redirect;

typedef struct s_command
{
	char		*argv[MAX_ARGS];
	t_redirect	redirects[MAX_REDIRS];
	int			redirect_count;
}	t_command;

typedef struct s_env
{
	char		**env;
	char		***env_matrix;
	char		***env_3;
}	t_env;

typedef enum e_builtin
{
	BUILTIN_NONE,
	BUILTIN_ECHO,
	BUILTIN_PWD,
	BUILTIN_ENV,
	BUILTIN_EXPORT,
	BUILTIN_UNSET,
	BUILTIN_CD,
	BUILTIN_EXIT
}	t_builtin;

typedef struct s_pipeline
{
	t_command	*cmds;
	int			count;
	pid_t		*pids;
}	t_pipeline;

//minishell_main.c
bool		ft_find_paths(char **env);
char		***ft_env_3(char **env);
bool		ft_find_paths(char **env);
char		**ft_tokenization(char *input, char ***env);

//minishell_quotes.c
char		**ft_quotes(char *input);

//minishell_quotes_bis.c
char		**ft_first_split(char *input);

//minishell_split.c
char		**ft_split_minishell(char **token);

//minishell_expand.c
int			ft_in_or_out(int in, char c);
char		**ft_expansion(char **token, char ***env);

//minishell_expand_aux.c
char		*ft_clean_token(char *str);

//minishell_biult_in_1.c
void		ft_export_0(char **env);
int			ft_export_1_aux(char ***matrix, char *str);
char		**ft_export_1(char **env, char *var, char ***env_3);

//minishell_biult_in_2.c
char		**ft_cd(char *dir, char **env, char ***env_3);
char		**ft_unset(char *unwanted, char **envp);

//minishell_biult_in_3.c
void		ft_pwd(void);
void		ft_env(char **copy_envp);
void		ft_echo_n(char **command);
void		ft_echo(char **command);

//minishell_signals.c
void		ft_sigaction(void);

//minishel_exec.c
int			apply_redirections(t_command *cmd);
int			run_builtin(t_command *cmd, char ***envp_matrix, char ***env_3);
void		run_command(t_command *cmd, char ***envp_matrix, char ***env_3);
void		run_pipeline(t_pipeline *pl, t_env *st_env);

//minishell_parser.c
int			parse_command(char **tokens, t_command *cmd);
int			parse_pipeline(char **tokens, t_pipeline *pl);

//minishell_find_comand.c
char		*find_command_path(char *cmd);

//utils.c
char		*ft_strjoin_mini(char const *s1, char const *s2);
t_builtin	identify_builtin(char *cmd);
char		*next_token(char **str, const char *delim);
int			contains_pipe(char **tokens);
void		free_command(t_command *cmd);
void		free_pipeline(t_pipeline *pl);
void		ft_free_pipes(int **pipes, int n);
void		close_all_pipes(int **pipes, int count);

#endif
