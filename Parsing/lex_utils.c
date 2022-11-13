/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:47:34 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/13 15:31:23 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

	// if (empty_string(lex, quote))
int	is_symbol(char c)
{
	if (!c)
		return (0);
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	end_reached(t_lex *lex, char quote, int *flag)
{
	if (*flag == 1 && ft_isblank(lex->c))
		return (1);
	if (lex->c == quote)
	{
		if (lex->i < lex->str_len - 1 && !ft_isblank(lex->string[lex->i + 1]))
		{
			*flag = 1;
			lex_forward(lex);
		}
		else
			return (1);
	}
	return (0);
}

int	empty_string(t_lex *lex, char quote)
{
	lex_forward(lex);
	if (lex->c == quote)
		return (1);
	return (0);
}

char	get_opposite_quote(char quote)
{
	if (quote == '\"')
		return ('\'');
	else if (quote == '\'')
		return ('\"');
	else
		return (0);
}

char	*lex_strdup(t_lex *lex, int n)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * n + 1);
	if (!copy)
		malloc_fail();
	i = 0;
	while (i < n)
	{
		copy[i] = lex->c;
		lex_forward(lex);
		i++;
	}
	lex_backward(lex);
	copy[i] = 0;
	return (copy);
}
