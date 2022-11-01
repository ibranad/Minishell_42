/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:05 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 11:27:15 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

// void	execute(t_cmdl *cmd, char **env)
// {
// 	int	size;

// 	if (!cmd) // Why this condition 
// 		return ;
// 	size = cmdline_size(cmd);
// 	if (size == 1)
// 		run_sole_cmd(cmd, env, 0);
// 	else
// 		pipex(cmd, env);
// }



void	execute(t_cmdl *cmd, char **env)
{
	int	size;

	if (!cmd) // Why this condition 
		return ;
	size = cmdline_size(cmd);
	if (size == 1)
		run_sole_cmd(cmd, env, command_validity(cmd));
	else
		pipex(cmd, env);
}
