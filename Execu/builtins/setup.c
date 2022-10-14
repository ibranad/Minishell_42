/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/14 15:44:20 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

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
