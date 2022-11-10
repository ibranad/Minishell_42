/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:03:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 18:00:54 by obouizga         ###   ########.fr       */
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
}

int	write_to(int fd)
{
	if (fd < 0)
		return (0);
	if (dup2(fd, STDOUT_FILENO) == -1)
		dup2_fail();
	return (1);
}
