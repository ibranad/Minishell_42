/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 15:41:13 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

// t_envl	*setup(char **env)
// {
// 	int		i;
// 	t_envl	*envl;
// 	char	**entry;
	
// 	i = 0;
// 	entry = get_entry(env[i]);
// 	if (!entry)
// 		return (NULL);
// 	envl = lstnew(entry[0], entry[1]);
// 	free(entry);
// 	while (env[++i])
// 	{
// 		entry = get_entry(env[i]);
// 		if (!ft_strcmp(entry[0], "OLDPWD"))
// 		{
// 			free(entry[0]);
// 			free(entry[1]);
// 			free(entry);
// 			continue ;
// 		}
// 		lstadd_back(&envl, lstnew(entry[0], entry[1]));
// 		free(entry);
// 	}
// 	return (envl);
// }

void	setup(char **env)
{
	int		i;
	t_envl	*envl;
	char	**entry;
	
	i = 0;
	entry = get_entry(env[i]);
	if (!entry)
	{
		shell.env = NULL;
		return ;	
	}
	envl = lstnew(entry[0], entry[1]);
	free(entry);
	while (env[++i])
	{
		entry = get_entry(env[i]);
		if (!ft_strcmp(entry[0], "OLDPWD"))
		{
			free(entry[0]);
			free(entry[1]);
			free(entry);
			continue ;
		}
		lstadd_back(&envl, lstnew(entry[0], entry[1]));
		free(entry);
	}
	shell.env = envl;
}


void	set_commands_exit_status(void)
{
	if (!WIFEXITED(shell.status))
		shell.status += 128;
	else
		shell.status = WEXITSTATUS(shell.status);
}

void	set_builtins_exit_status(int status)
{
	shell.status = status;
}