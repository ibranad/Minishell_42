/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:16:54 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/22 11:05:45 by ibnada           ###   ########.fr       */
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
}				g_shell;

g_shell	shell;
# include "ascii.h"
# include "utils.h"
# include  "exp.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"
t_cmdl	*parser(t_envl *envl);
void	execute(t_cmdl *cmd, g_shell shell);
void	handle_signals(void);
#endif

