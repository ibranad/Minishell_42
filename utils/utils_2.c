/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:01:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/15 18:42:53 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

pid_t	ft_fork(void)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		fork_fail();
	return (id);
}
void	display_arr(pid_t *pids, int n)
{
	for (int i = 0; i < n; i++)
		printf("[%d]\n", pids[i]);
}

void	wait_all(int *status)
{
	while (wait(status) != -1)
		continue ;
}

int	look_for(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
