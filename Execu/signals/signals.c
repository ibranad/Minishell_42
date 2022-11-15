/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:25:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	sigquit_child_handle(int sigint)
{
	(void)sigint;
	write(1, "\n", 1);
	exit(SIGQUIT);
}

void	before_readline_handle(void)
{
	write(1, "\n", 1);
	if (g_shell.in_heredoc)
	{
		g_shell.here_sigint = 1;
		g_shell.here_stdin_keep = dup(0);
		close(0);
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_shell.status = 1;
}

void	after_readline_handle(void)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	handle_signals(void (*func))
{
	signal(SIGINT, func);
	signal(SIGQUIT, SIG_IGN);
}
