/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 18:38:09 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

//when exit is given too many args (> 1) it 'll exit with a number = 1.
// and it'll print a message saying "exit: too many arguments"

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

static void 	too_many_arguments(char *str)
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
		exit(shell.status);
}
p