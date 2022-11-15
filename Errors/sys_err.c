/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:30:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	close_fail(void)
{
	putstr_fd("Error: close fail\n", 2);
	exit(EXIT_FAILURE);
}

void	execve_fail(void)
{
	putstr_fd("Error: execve failed\n", 2);
	exit(EXIT_FAILURE);
}

void	fork_fail(void)
{
	putstr_fd("Error : fork failed\n", 2);
	exit(EXIT_FAILURE);
}

void	malloc_fail(void)
{
	putstr_fd("Error : Malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	pipe_fail(void)
{
	putstr_fd("Error: Pipe fail\n", 2);
	exit(EXIT_FAILURE);
}
