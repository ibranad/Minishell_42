/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/01 15:22:50 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

t_envl	*set_env(char **env)
{
	int		i;
	t_envl	*envl;
	char	**entry;
	
	i = 0;
	entry = split(env[i], '=');
	envl = lstnew(entry[0], entry[1]);
	while (env[++i])
	{
		entry = split(env[i], '=');
		if (!ft_strcmp(entry[0], "OLDPWD"))
			continue ;
		lstadd_back(&envl, lstnew(entry[0], entry[1]));
	}
	return (envl);
}
