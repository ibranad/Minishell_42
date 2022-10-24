/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:10:40 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/24 18:50:28 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

/*
* Make a founction that checks for input , and fill the linked list in_fd var
* Make a founction that checks for output , and fill the linked list out_fd var
*
* cc -lreadline heredoc.c ../Libft/ft_strlen.c ../Libft/ft_strncmp.c
*
* pipe heredoc > << cat | wc -l :: it does only work on zsh
*/

int	ft_hd_short(char *line, char *lim, int pip)
{
	char	c;

	c = '\n';
	if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
		return (-1);
	else
	{
		write(pip, &c, 1);
		write(pip, line, ft_strlen(line));
	}
	return (0);
}

int	ft_heredoc(char *lim)
{
	char	*line;
	int		pip[2];
	int		e;
//needs protection from NULL
	if (!lim)
		return (-1);
	pipe(pip);
	line = readline("> ");
	if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
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
		free (line);
	}
	free (line);
	close(pip[1]);
	return (pip[0]);
}

