/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 17:26:13 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	free_entry(char **entry)
{
	free(entry[0]);
	free(entry[1]);
	free(entry);
	return (1);
}

void	setup(char **env)
{
	int		i;
	t_envl	*envl;
	char	**entry;

	i = 0;
	entry = get_entry(env[i]);
	if (!entry)
	{
		g_shell.env = NULL;
		return ;
	}
	envl = lstnew(entry[0], entry[1]);
	free(entry);
	while (env[++i])
	{
		entry = get_entry(env[i]);
		if (!ft_strcmp(entry[0], "OLDPWD") && free_entry(entry))
			continue ;
		lstadd_back(&envl, lstnew(entry[0], entry[1]));
		free(entry);
	}
	g_shell.env = envl;
}

void	set_commands_exit_status(void)
{
	if (!WIFEXITED(g_shell.status))
		g_shell.status += 128;
	else
		g_shell.status = WEXITSTATUS(g_shell.status);
}

void	set_builtins_exit_status(int status)
{
	g_shell.status = status;
}
