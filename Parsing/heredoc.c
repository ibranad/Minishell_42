/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:10:40 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/08 11:06:30 by ibnada           ###   ########.fr       */
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
	if (shell.h_doc == -1 || !line
		|| ft_strncmp(line, lim, ft_strlen(lim)) == 0)
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

int	ft_heredoc(char *lim)
{
	t_hdoc	s;

	if (!lim)
		return (-1);
	hdoc_init(lim, &s);
	signal(SIGINT, stop_here);
	s.line = readline("> ");
	if (!s.line || ft_strncmp(s.line, lim, s.lim_l) == 0)
	{
		hd_free_close(&s);
		return (s.pip[0]);
	}
	write(s.pip[1], s.line, ft_strlen(s.line));
	free(s.line);
	while (1)
	{
		s.line = readline("> ");
		s.e = ft_hd_short(s.line, lim, s.pip[1]);
		if (s.e == -1)
			break ;
		free(s.line);
	}
	hd_free_close(&s);
	return (s.pip[0]);
}
