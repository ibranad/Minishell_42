/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:53:53 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/03 10:25:38 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

//when exit is given too many args (> 1) it 'll exit with a number = 1.
// and it'll print a message saying "exit: too many arguments"
void 	too_many_arguments(void)
{
	putstr_fd("Minishell: exit: too many arguments\n", STDERR_FILENO);
	exit(1);
}

void	__exit(char **args)
{
	putstr_fd("exit\n", STDOUT_FILENO);
	if (vector_len(args) > 2)
		too_many_arguments();
	else if (vector_len(args) == 2)
		exit(ft_atoi(*(args + 1)));
	else
		exit(1);
}
