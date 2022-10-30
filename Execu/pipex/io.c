/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:03:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 09:09:46 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	read_from(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		dup2_fail();
}

void	write_to_pipe(int *fildes)
{
	if (dup2(fildes[WRITE_END], STDOUT_FILENO) == -1)
		dup2_fail();
	if (close(fildes[READ_END]) == -1)
		close_fail();
}

void	read_from_pipe(int *fildes)
{
	if (dup2(fildes[READ_END], STDIN_FILENO) == -1)
		dup2_fail();
	if (close(fildes[WRITE_END]) == -1)
		close_fail();
	// dprintf(2, "%s\n",s);
}

void	write_to(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
		dup2_fail();	
}

