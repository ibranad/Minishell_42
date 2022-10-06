/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/06 15:58:10 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_length(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

//TESTING
t_envl	*set_env(char **env)
{
	int		i;
	t_envl	*envl;

	i = 0;
	envl = lstnew(split(env[i], '='), i);
	while (env[++i])
		lstadd_back( &envl, lstnew(split(env[i], '='), i));
	return (envl);
}
