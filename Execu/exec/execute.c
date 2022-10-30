/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:05 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 18:04:49 by obouizga         ###   ########.fr       */
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
		run_sole_cmd(cmd, env, 0);
	else
		pipex(cmd, env);
}
