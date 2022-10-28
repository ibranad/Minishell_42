/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:25:47 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/28 10:50:39 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

// void	foo(void)
// {
// 	//there's a handler before the readline
// 	// the readline
// 	// a handler after the readline 
// }

void	interrupt_handle()
{
	write(1, "\n", 1);
	rl_on_new_line(); // Tell the update functions that we moved onto a new line, usually after outputting a newline.
	rl_replace_line("", 0); // this replaces the content of the rl_line_buffer with the passed value
	rl_redisplay();
}


void	foo(void)
{
	
}

void	handle_signals()
{
	signal(SIGINT, interrupt_handle);
	signal(SIGQUIT, SIG_IGN);
}


//For Control-D signal
// if the rl_line_buffer is empty this signal causes the terminal to exit
// if the rl_line_buffer contains something this signal get ignored
// if we're in here_doc or the command is reading input from stdin the reading
// stops