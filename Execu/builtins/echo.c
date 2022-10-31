/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:38:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/30 18:12:10 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"
// * The parser should take the command echo and then make 
// * sure its lowercase otherwise he makes it so;
/*
	* {"-n", str1, str2, str3, ..., NULL}
*/


/*
	* there's two major cases:
		* printing WITH a new_line: This case the default (so we'll print all the given strings followed by 
		* a new line)
		* printing WITHOUT a new_line;
			*We'll search for the last valid option and start printing from the string that followed
*/

int	vaild_option(char *s)
{
	int i;

	i = 1;
	if (s[0] != '-')
		return (0);
	while (s[i])
		if (s[i++] != 'n')
			return (0);
	return (1);
}

int start_from(int ac, char **av)
{
	int i;

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
	char	c;
	int 	start;
	int		i;
	
	start = start_from(ac , av);
	i = start;
	c = ' ';
	while (i < ac)
	{
		if (i == ac - 1)
			c = 0;
		printf("%s%c", av[i++], c);
	}
	if (!start)
		printf("\n");
}
