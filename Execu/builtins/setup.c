/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 12:37:16 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

t_envl	*set_env(char **env)
{
	int		i;
	t_envl	*envl;
	char	**entry;
	
	i = 0;
	entry = get_entry(env[i]);
	if (!entry)
		return (NULL);
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
	return (envl);
}
