/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:05 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 14:26:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	execute(t_cmdl *cmd, char **env)
{
	int	size;

	if (!cmd || shell.here_sigint)
		return ;
	size = cmdline_size(cmd);
	if (size == 1)
		run_sole_cmd(cmd, env, command_validity(cmd));
	else
		pipex(cmd, env);
}
