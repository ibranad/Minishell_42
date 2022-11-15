/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:02:43 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 15:31:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	in_here_doc_handle(t_exp *s, char *in)
{
	char	*ptr;

	ptr = NULL;
	if (in[s->g_i] == '<')
	{
		s->g_i++;
		s->g_i++;
		ptr = s->out;
		s->out = ft_strjoin(s->out, "<<");
		free(ptr);
	}
	while ((in[s->g_i] == ' ' || in[s->g_i] == '\t') && in[s->g_i])
		s->g_i++;
	if (in[s->g_i] == DQ)
		dq_short(s, in);
	else if (in[s->g_i] == SQ)
		sq_expanding(s, in);
	else
		exp_else_sp(s, in);
}

void	dq_short(t_exp *s, char *in)
{
	char	*ptr;

	ptr = NULL;
	s->g_i++;
	ptr = s->out;
	s->not_out = get_until_d_quote(&in[s->g_i]);
	s->out = ft_strjoin(s->out, s->not_out);
	free(ptr);
	s->g_i += ft_strlen(s->not_out) + 1;
	free(s->not_out);
}

char	*get_until_char(char *in, char c, char d)
{
	int		i;
	char	*out;

	i = 0;
	while (in[i])
	{
		if (in[i] == c || in[i] == d)
			break ;
		i++;
	}
	out = ft_substr(in, 0, i);
	return (out);
}

void	exp_else_sp(t_exp *s, char *in)
{
	char	*ptr;

	ptr = NULL;
	ptr = s->out;
	s->not_out = get_until_char(&in[s->g_i], ' ', '\t');
	s->out = ft_strjoin(ptr, s->not_out);
	free(ptr);
	s->g_i += ft_strlen(s->not_out);
	free(s->not_out);
}
