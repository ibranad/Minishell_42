/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:30:35 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 12:33:51 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void    close_fail()
{
		putstr_fd("Error: close fail\n", 2);
        exit(EXIT_FAILURE);
}

void    dup2_fail()
{
		putstr_fd("Error: dup2 Failed\n", 2);
        exit(EXIT_FAILURE);
}

void    execve_fail(void)
{
		putstr_fd("Error: execve failed\n" , 2);
        exit(EXIT_FAILURE);
}

void    fork_fail(void)
{
		putstr_fd("Error : fork failed\n", 2);
        exit(EXIT_FAILURE);
}


void    malloc_fail(void)
{
		putstr_fd("Error : Malloc failed\n", 2);
        exit(EXIT_FAILURE);
}

void    pipe_fail(void)
{
		putstr_fd("Error: Pipe fail\n", 2);
        exit(EXIT_FAILURE);
}

void	_errno(void)
{
	printf("errno : %i\n", errno);
	exit(0);
}

void	identifier_err(char *s)
{
	printf("export: `%s': not a valid identifier\n", s);
	exit(EXIT_FAILURE);
}