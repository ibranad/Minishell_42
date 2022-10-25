/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:22:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/25 09:29:09 by obouizga         ###   ########.fr       */
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
			return ((split(curr->value, ':')));
		curr = curr->next;
	}
	return (NULL);
}

char	*fetch_path(char *cmd, char **paths)
{
	int		i;
	char	*path;
	
	if (!paths)
		path_unset(cmd);
	i = 0;
	str_tolower(cmd);
	if (!access(cmd, F_OK))
		return (cmd);
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
	while (curr)
	{
		if (!ft_strcmp(curr->key, key))
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}