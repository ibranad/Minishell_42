/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:05 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/28 07:43:32 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	execute(t_cmdl *cmd, g_shell shell, char **env)
{
	int	size;

	if (!cmd)
		return ;
	size = cmdline_size(cmd);
	if (size == 1)
	{
		if (!cmd->path && cmd->builtin == -1)
			return ;
		if (cmd->builtin == -1)
			run_sole_cmd(cmd, shell, env);
		else
			run(cmd, shell, env);
	}
	else
		pipex(cmd, shell, env);
}
