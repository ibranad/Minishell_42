/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:16:54 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/11 10:11:18 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "lib.h"

# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
#define RESET_COLOR "\e[m"
typedef struct s_lex
{
	char	c;
	size_t	i;
	char	*string;
	size_t	str_len;
}				t_lex;

typedef enum
{
	_head,
	_chev,
	_ichev,
	_dchev,
	_dichev,
	_pipe,
	_word,
}	e_nat;

typedef struct s_toklist
{
	e_nat				nature;
	char				*lexeme;
	struct s_toklist	*next;
}					t_toklist;

typedef struct s_cmdl
{
	int				idx;
	char			*path;
	char			**args;
	int				in_fd;
	int				out_fd;
	int				builtin;
	struct s_cmdl	*next;
	
}				t_cmdl;

typedef struct s_envl
{
	char	*key;
	char	*value;
	int		idx;
	struct s_envl	*next;
}				t_envl;

typedef struct s_shell
{
	t_envl	*env;
	int		status;
	int		paths_existence;
	int		in_heredoc;
	int		here_sigint;
	int		here_stdin_keep;
	int		status_state;
	int		prs_error;
	int		concat;
}				g_shell;

g_shell	shell;
# include "ascii.h"
# include "utils.h"
# include  "exp.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"
t_cmdl	*parser();
void	execute(t_cmdl *cmd, char **env);
void	handle_signals(void (*func));
void	after_readline_handle();
void	before_readline_handle();

#endif

