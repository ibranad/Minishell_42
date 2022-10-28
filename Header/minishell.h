/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:16:54 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/28 07:42:08 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "lib.h"

# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

typedef struct s_cmdl
{
	int				idx;
	char			*path;
	char			**args;
	int				in_fd;
	int				out_fd;
	int				builtin;
	int				is_exec;
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
	void	**builtin_func;
	int		status;
}				g_shell;

g_shell	shell;
# include "ascii.h"
# include "utils.h"
# include  "exp.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"
t_cmdl	*parser(g_shell shell);
void	execute(t_cmdl *cmd, g_shell shell, char **env);
void	handle_signals(void);
#endif

