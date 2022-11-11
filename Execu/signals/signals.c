/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:25:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/11 20:03:43 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
//For Control-D signal
// if the rl_line_buffer is empty this signal causes the terminal to exit
// if the rl_line_buffer contains something this signal get ignored
// if we're in here_doc or the command is reading input from stdin the reading
// stops

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
