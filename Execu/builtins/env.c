/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:48:21 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/03 12:39:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
static void	 too_many_args(char *argument)
{
	putstr_fd("env: ", STDERR_FILENO);
	putstr_fd(argument, STDERR_FILENO);
	putstr_fd(": No such file or directory\n", STDERR_FILENO);
	// exit(1);
}
void	print_env(t_envl *envl)
{
	t_envl *curr;

	curr = envl;
	while (curr)
	{
		printf("%s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
}

void	_env(char **args, t_envl *envl)
{
	if (vector_len(args) > 1)
		too_many_args(*(args + 1));
	else
		print_env(envl);
}