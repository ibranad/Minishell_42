/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:18:13 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/16 15:32:48 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

t_lex	*init_lex(char *cmd_line)
{
	t_lex	*lex;

	lex = malloc(sizeof(t_lex));
	if (!lex)
		malloc_fail();
	lex->string = cmd_line;
	lex->str_len = ft_strlen(lex->string);
	lex->i = 0;
	lex->c = lex->string[lex->i];
	return (lex);
}

void	lex_forward(t_lex *lex)
{
	if (lex->c)
	{
		lex->i++;
		lex->c = *(lex->string + lex->i);
	}
}

void	lex_backward(t_lex *lex)
{
	if (lex->i)
	{
		lex->i--;
		lex->c = *(lex->string + lex->i);
	}
}

char	*lex_gather_str(t_lex *lex, char quote)
{
	char	*string;

	string = NULL;
	lex_forward(lex);
	while (lex->c && lex->c != quote)
	{
		string = charjoin(string, lex->c);
		lex_forward(lex);
	}
	if (!lex->c)
		return (NULL);
	else if (lex->c == quote)
	{
		lex_forward(lex);
		return (string);
	}
	return (NULL);
}	

