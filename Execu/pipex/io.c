/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:03:50 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/27 11:27:55 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	read_from(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		dup2_fail(fd);
}

void	write_to_pipe(int *fildes)
{
	if (dup2(fildes[WRITE_END], STDOUT_FILENO) == -1)
		dup2_fail(fildes[WRITE_END]);
	if (close(fildes[READ_END]) == -1)
		close_fail(fildes[READ_END]);
}

void	read_from_pipe(int *fildes)
{
	if (dup2(fildes[READ_END], STDIN_FILENO) == -1)
		dup2_fail(fildes[READ_END]);
	if (close(fildes[WRITE_END]) == -1)
		close_fail(fildes[WRITE_END]);
}

void	write_to(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
		dup2_fail(fd);	
}

