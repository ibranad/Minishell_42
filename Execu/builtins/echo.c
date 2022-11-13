/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:38:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 16:59:59 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	vaild_option(char *s)
{
	int	i;

	i = 1;
	if (s[0] != '-')
		return (0);
	while (s[i])
		if (s[i++] != 'n')
			return (0);
	return (1);
}

int	start_from(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac && vaild_option(av[i]))
		i++;
	if (i != ac)
		return (i);
	else
		return (0);
}

void	_echo(int ac, char **av)
{
	int	start;
	int	i;

	start = start_from(ac, av);
	i = start;
	while (i < ac)
	{
		if (i == ac - 1)
			printf("%s", av[i++]);
		else
			printf("%s ", av[i++]);
	}
	if (!start)
		printf("\n");
	set_builtins_exit_status(0);
}
