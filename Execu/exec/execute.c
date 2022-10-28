/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:05 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/28 16:14:31 by obouizga         ###   ########.fr       */
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
/*
* does builtin get strlowered before get run 
*/
// and where

// ? Why after unsetting the path, builtin typed uppercase 
// don't work
// IS IT THE SAME IN BASH?? --> YES
/*
	Conclusion:
	the origin of this problem is that some "builtins" are not and
	they're executed using their path for example echo gets executed from /bin/echo this 
	is not the case for  export and unset
	the thing is that builtins that were given in the subjects are not seemingly builtins
	as [echo, pwd, cd, env] those are all executed using their paths. In contrast, [export, 
	unset, exit] those are  builtins and unsetting the PATH doesn't impact 
	
	Observation:
		PATH SET: the bash is case-INSENSITIVE for both builtins and command
		PATH UNSET: the bash is case-SENSITIVE for [echo, pwd, cd], they run when lowered and don't
					when containing at least on uppercase char. For other commands they don't run at all for 
					the reason of path not for the reason of case.
	


	EXPERIMENTATIONS:
	 IN CASE OF WRITING UPPERCASE ECHO, IS IT MY ECHO
	 THAT GETS CALLED OR THE ECHO DWELLIGN IN PATH ??
	 let's see
*/
