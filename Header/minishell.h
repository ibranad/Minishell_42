/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:16:54 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 17:05:22 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "lib.h"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RESET_COLOR "\e[m"

# include "ascii.h"
# include "utils.h"
# include  "exp.h"
# include "lexer.h"
# include "parser.h"
# include "exec.h"

typedef struct g_shell
{
	t_envl	*env;
	int		status;
	int		paths_existence;
	int		in_heredoc;
	int		here_sigint;
	int		here_stdin_keep;
	int		status_state;
	int		prs_error;
}			t_shell;

t_shell	g_shell;

t_cmdl	*parser(void);
void	execute(t_cmdl *cmd, char **env);
void	handle_signals(void (*func));

#endif
