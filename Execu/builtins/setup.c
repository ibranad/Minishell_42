/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:40:08 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/23 15:14:56 by obouizga         ###   ########.fr       */
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

// void **set_builtin_arr(void)
// {
// 	void	*(*builtin_arr);

// 	builtin_arr = malloc(sizeof(void (*)) * 7);
// 	if (!builtin_arr)
// 		malloc_fail();
// 	builtin_arr[0] = _echo;
// 	builtin_arr[1] = change_dir;
// 	builtin_arr[2] = _pwd;
// 	builtin_arr[3] = _export;
// 	builtin_arr[4] = _unset;
// 	builtin_arr[5] = _env;
// 	builtin_arr[6] = _exit;
// 	return (builtin_arr);
// }
