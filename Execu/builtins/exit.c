/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/05 17:19:06 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

//when exit is given too many args (> 1) it 'll exit with a number = 1.
// and it'll print a message saying "exit: too many arguments"
static void 	too_many_arguments(void)
{
	putstr_fd("Minishell: exit: too many arguments\n", STDERR_FILENO);
	// exit(1);
}

static int	err_message(char *str)
{
	putstr_fd("Minishell: exit: ", STDERR_FILENO);
	putstr_fd(str, STDERR_FILENO);
	putstr_fd(": numeric argument required\n", STDERR_FILENO);
	return (255);
}

static int	check_alphanumeric(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isalnum(str[i]))
			return (err_message(str));
	return (ft_atoi(str));		
}

void	__exit(char **args)
{
	putstr_fd("exit\n", STDOUT_FILENO);
	if (vector_len(args) > 2)
		too_many_arguments();
	else if (vector_len(args) == 2)
		exit(check_alphanumeric(*(args + 1)));
	else
		exit(1);
}
