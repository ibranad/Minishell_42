/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:06:23 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/05 11:33:02 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	pipex(t_cmdl *cmdl, char **env)
{
	int		fildes[2];
	t_cmdl	*curr;

	curr = cmdl;
	while (curr->next)
	{
		pipe(fildes);
		if (!ft_fork())
		{
			if (!curr->idx)
				first_cmd(fildes, curr,  command_validity(curr), env);
			else
				mid_cmd(fildes, curr, command_validity(curr), env);
		}
		read_from_pipe(fildes);
		if (close(fildes[READ_END]) == -1)
			close_fail();
		curr = curr->next;
	}
	if (!ft_fork())
		last_cmd(curr, command_validity(curr), env);
	if (close(0) == -1)
			close_fail();
	wait_all();
}
/*
	WHEN DEALING WITH AN END OF A PIPE WE SHOULD CLOSE THE OPPOSITE END
*/