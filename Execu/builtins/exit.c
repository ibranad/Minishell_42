/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:24 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

static int	err_message(char *str)
{
	putstr_fd("Minishell: exit: ", STDERR_FILENO);
	putstr_fd(str, STDERR_FILENO);
	putstr_fd(": numeric argument required\n", STDERR_FILENO);
	return (255);
}

static int	check_numeric(char *str)
{
	if (not_integer(str))
		return (err_message(str));
	return (ft_atoi(str));
}

static void	too_many_arguments(char *str)
{
	if (not_integer(str))
		exit(check_numeric(str));
	putstr_fd("Minishell: exit: too many arguments\n", STDERR_FILENO);
	set_builtins_exit_status(1);
}

void	__exit(char **args)
{
	putstr_fd("exit\n", STDOUT_FILENO);
	if (vector_len(args) > 2)
		too_many_arguments(*(args + 1));
	else if (vector_len(args) == 2)
		exit(check_numeric(*(args + 1)));
	else
		exit(g_shell.status);
}
