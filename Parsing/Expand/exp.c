/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/07 23:46:25 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	dollar_white_space(t_exp *s, char *in)
{
	char	*ptr;

	ptr = NULL;
	ptr = s->out;
	s->not_out = get_until_dollar(&in[s->g_i]);
	s->out = ft_strjoin(ptr, s->not_out);
	free(ptr);
	s->g_i += ft_strlen(s->not_out);
	free(s->not_out);
}

void	dollar_ques_mark(t_exp *s, char *in)
{
	(void)in;
	char	*ptr;
	char	*ptr2;

	ptr = NULL;
	ptr2 = s->out;
	ptr = ft_itoa(shell.status);
	s->g_i++;
	s->out = ft_strjoin(ptr2, ptr);
	s->g_i++;
	free(ptr);
	free(ptr2);
}

char	*expander(t_envl *envl, char *in)
{
	t_exp	s;

	struct_init(&s);
	while (in[s.g_i] != '\0')
	{
		if (in[s.g_i] == '$' && (in[s.g_i + 1] == '_'
				|| ft_isalnum(in[s.g_i + 1])))
			dollar_expanding(envl, &s, in);
		else if (in[s.g_i] == '<' && in[s.g_i + 1] == '<')
			in_here_doc_handle(&s, in);
		else if (in[s.g_i] == '$' && in[s.g_i + 1] == '?')
			dollar_ques_mark(&s, in);
		else if (in[s.g_i] == '$' && !in[s.g_i + 1])
			dollar_only_case(&s, in);
		else if (in[s.g_i] == '$' && (in[s.g_i + 1] == '\''
				|| in[s.g_i + 1] == '\"'))
			s.g_i++;
		else if (in[s.g_i] == '\"')
			dq_expanding(envl, &s, in);
		else if (in[s.g_i] == '\'')
			sq_expanding(&s, in);
		else if (in[s.g_i] == '$' && (in[s.g_i + 1] == ' '
				|| in[s.g_i + 1] == '\t'))
			dollar_white_space(&s, in);
		else
			exp_else(&s, in);
	}
	return (s.out);
}

int	unreq_meta_char(char *in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		if (in[i] == '\"' || in[i] == '\'')
		{
			i++;
			while (in[i])
			{
				if (in[i] == '\"' || in[i] == '\'')
					break ;
			i++;
			}
		}
		if (in[i] == '#' || in[i] == '`' || in[i] == '&' || in[i] == '*'
			|| in[i] == '(' || in[i] == ')' || in[i] == '\\' || in[i] == '['
			|| in[i] == ']' || in[i] == '{' || in[i] == '}' || in[i] ==';'
			|| in[i] == '!')
		{
			printf("Syntax error : Illegal character `%c`\n", in[i]);
			return (-2);
		}
		i++;
	}
	return (0);
}

int	check_meta_char(char *in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		if ((in[i] == '>') || (in[i] == '<') || (in[i] == '|'))
		{
			error_printing();
			return (-3);
		}
		else if (in[i] == ' ' || in[i] == '\t')
			i++;
		else
			break ;
	}
	return (0);
}
