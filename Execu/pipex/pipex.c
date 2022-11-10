/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/09 17:47:50 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	pipex(t_cmdl *cmdl, char **env)
{
	int		fildes[2];
	t_cmdl	*curr;

	curr = cmdl;
	while (curr)
	{
		pipe(fildes);
		if (!ft_fork())
		{
			if (!curr->idx)
				first_cmd(fildes, curr,  command_validity(curr), env);
			else if (!curr->next)
				last_cmd(curr, command_validity(curr), env);
			else
				mid_cmd(fildes, curr, command_validity(curr), env);
		}
		read_from_pipe(fildes);
		if (close(fildes[READ_END]) == -1)
			close_fail();
		curr = curr->next;
	}
	if (close(0) == -1)
			close_fail();
	wait_all();	
}