/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/07 15:27:25 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
