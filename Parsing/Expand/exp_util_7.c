/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_util_7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:31:18 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/15 20:59:32 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	expand_dq_sp_else_short(t_exp_sp *p, char *in)
{
	char	*ptr;

	ptr = NULL;
	ptr = p->out;
	p->not_expa = get_until_dollar(&in[p->i_g]);
	p->out = ft_strjoin(p->out, p->not_expa);
	free(ptr);
	p->i_g += ft_strlen(p->not_expa);
	free(p->not_expa);
}

char	*add_char_first(char *in, char c)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	out = malloc(sizeof(char) * ft_strlen(in) + 2);
	out[j++] = c;
	while (in[i])
	{
		out[j] = in[i];
		i++;
		j++;
	}
	out[j] = '\0';
	return (out);
}

void	exp_else(t_exp *s, char *in)
{
	char	*ptr;

	ptr = s->out;
	s->not_out = get_until_dollar(&in[s->g_i]);
	s->out = ft_strjoin(ptr, s->not_out);
	free(ptr);
	s->g_i += ft_strlen(s->not_out);
	free(s->not_out);
}

int	check_unrequired_by_subject(char *in)
{
	if (unclosed_quote(in) == 1)
		return (-1);
	// if (multi_in(in) < 0)
	// 	return (-2);
	// if (multi_out(in) < 0)
	// 	return (-3);
	// if (space_between_in(in) < 0)
	// 	return (-3);
	// if (space_between_out(in) < 0)
	// 	return (-3);
	return (0);
}

void	dollar_only_case(t_exp *s, char *in)
{
	char	*ptr;

	(void)in;
	ptr = NULL;
	ptr = s->out;
	s->out = ft_strjoin(s->out, "$");
	s->g_i += 1;
	free(ptr);
}
