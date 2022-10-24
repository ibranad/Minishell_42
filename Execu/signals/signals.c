/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:25:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/24 14:48:16 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	handler(int signum)
{
	if (signum == SIGQUIT)
		printf("SIGQUIT OCCURED\n");
	else if (signum == SIGINT)
		printf("SIGINT OCCURED\n");
}

void	interrupt_handle()
{
	write(1, "\n", 1);
	rl_on_new_line(); // Tell the update functions that we moved onto a new line, usually after outputting a newline.
	rl_replace_line("", 0); // this replaces the content of the rl_line_buffer with the passed value
	rl_redisplay();
}

void	handle_signals()
{
	signal(SIGINT, interrupt_handle);
	signal(SIGQUIT, SIG_IGN);
}
