/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:05 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 07:28:19 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	execute(t_cmdl *cmd, char **env)
{
	int	size;

	if (!cmd)
		return ;
	size = cmdline_size(cmd);
	if (size == 1)
	{
		// if (!cmd->path && cmd->builtin == -1) //check this
		// 	return ;
		if (cmd->builtin == -1)
			run_sole_cmd(cmd, env);
		else
			run(cmd, env);
	}
	else
		pipex(cmd, env);
}
/*
	EXPERIMENTATIONS:
	 IN CASE OF WRITING UPPERCASE ECHO, IS IT MY ECHO
	 THAT GETS CALLED OR THE ECHO DWELLIGN IN PATH ??
	 let's see
*/
