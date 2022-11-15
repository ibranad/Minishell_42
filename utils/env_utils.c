/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:22:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

char	**get_paths(t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "PATH"))
		{
			g_shell.paths_existence = EXISTING;
			return ((split(curr->value, ':')));
		}
		curr = curr->next;
	}
	g_shell.paths_existence = UNEXISTING;
	return (NULL);
}

char	*fetch_path(char *cmd, char **paths)
{
	int		i;
	char	*path;

	if (!paths)
		return (NULL);
	else if (cmd && !*cmd)
		return (NULL);
	str_tolower(cmd);
	i = 0;
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		path = strjoin_s(paths[i], cmd);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_env_var(t_envl *envl, char *key)
{
	t_envl	*curr;

	curr = envl;
	if (!key)
		return (NULL);
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}

int	envl_len(t_envl *envl)
{
	t_envl	*curr;

	curr = envl;
	while (curr->next)
		curr = curr->next;
	return (curr->idx);
}
