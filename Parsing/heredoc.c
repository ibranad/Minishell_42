/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:10:40 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/08 08:58:16 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	stop_here()
{
	// in case of the occurence of a SIGINT signal we should not
	// be parsing till the end and we should return `t_cmdl cmdline as NULL`
	// so that the execute function will do nothing and hence we loop over
	// and give the prompt again
	// shell.h_doc = -1;	
}

int	ft_hd_short(char *line, char *lim, int pip)
{
	if (shell.h_doc == -1 || !line || ft_strncmp(line, lim, ft_strlen(lim)) == 0)
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

int	ft_heredoc(char *lim)
{
	char	*line;
	int		pip[2];
	int		e;
	int		lim_l;

	lim_l = ft_strlen(lim);
	if (!lim)
		return (-1);
	pipe(pip);
	signal(SIGINT, stop_here);
	line = readline("> ");
	if (!line || ft_strncmp(line, lim, lim_l) == 0)
	{
		free (line);
		close(pip[1]);
		return (pip[0]);
	}
	write(pip[1], line, ft_strlen(line));
	free(line);
	while (1)
	{
		line = readline("> ");
		e = ft_hd_short(line, lim, pip[1]);
		if (e == -1)
			break ;
		free(line);
	}
	free (line);
	close(pip[1]);
	return (pip[0]);
}

