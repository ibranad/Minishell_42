/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:25:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/12 14:40:56 by obouizga         ###   ########.fr       */
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
	if (shell.in_heredoc)
	{
		shell.here_sigint = 1;
		shell.here_stdin_keep = dup(0);
		close(0);
	}
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	shell.status = 1;
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
