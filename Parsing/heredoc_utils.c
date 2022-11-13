/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:57:24 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	ft_hd_short(char *line, char *lim, int pip)
{
	if (!line || ft_strncmp(line, lim, ft_strlen(lim)) == 0)
	{
		write(pip, "\n", 1);
		return (-1);
	}
	else
	{
		write(pip, "\n", 1);
		write(pip, line, ft_strlen(line));
	}
	return (0);
}

void	hdoc_init(char *lim, t_hdoc *s)
{
	pipe(s->pip);
	s->lim_l = ft_strlen(lim);
}

void	hd_free_close(t_hdoc *s)
{
	free (s->line);
	close(s->pip[1]);
}

int	stdin_keeper_hd(void)
{
	dup2(g_shell.here_stdin_keep, STDIN_FILENO);
	return (-1);
}
