/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:18:13 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/06 10:46:59 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"


char	*lex_gather_lexeme(t_lex *lex)
{
	char	*lexeme;

	lexeme = NULL;
	while (!ft_isblank(lex->c) && lex->c && !is_symbol(lex->c))
	{
		if (!is_quote(lex->c))
			lexeme = charjoin(lexeme, lex->c);
		else
			lexeme = ft_strjoin(lexeme, lex_gather_str(lex));
		lex_forward(lex);
	}
	lex_backward(lex);
	return (lexeme);
}

t_toklist	*new_io_token(t_lex *lex)
{
	if (lex->c == '<' && lex->string[lex->i + 1] == '<')
		return (new_token(_dchev, lex_strdup(lex, 2)));
	else if (lex->c == '<' && lex->string[lex->i + 1] != '<')
		return (new_token(_chev, lex_strdup(lex, 1)));
	else if (lex->c == '>' && lex->string[lex->i + 1] == '>')
		return (new_token(_dichev, lex_strdup(lex, 2)));
	else if (lex->c == '>' && lex->string[lex->i + 1] != '>')
		return (new_token(_ichev, lex_strdup(lex, 1)));
	return (NULL);
}

char	*gather_single_quoted(t_lex *lex)
{
	char	*substring;

	substring = NULL;
	lex_forward(lex);
	while (lex->c && lex->c != '\'')
	{
		substring = charjoin(substring, lex->c);
		lex_forward(lex);
	}
	lex_forward(lex);
	return (substring);
}

char	*gather_double_quoted(t_lex *lex)
{
	char	*substring;

	substring = NULL;
	lex_forward(lex);
	while (lex->c && lex->c != '\"')
	{
		substring = charjoin(substring, lex->c);
		lex_forward(lex);
	}
	lex_forward(lex);
	return (substring);
}

char	*gather_till_blank(t_lex *lex)
{
	char *substring;

	substring = NULL;
	while (lex->c && !ft_isblank(lex->c) && !is_quote(lex->c))
	{
		substring = charjoin(substring, lex->c);
		lex_forward(lex);
	}
	return (substring);
}

char	*lex_gather_str(t_lex *lex)
{
	char	*string;

	string = NULL;
	while (lex->c && !ft_isblank(lex->c))
	{
		if (lex->c == '\'')
			string = ft_strjoin(string, gather_single_quoted(lex));
		else if (lex->c == '\"')
			string = ft_strjoin(string, gather_double_quoted(lex));
		else if (!ft_isblank(lex->c) && lex->c)
			string = ft_strjoin(string, gather_till_blank(lex));
	}
	if (ft_isblank(lex->c))
		lex_backward(lex);
	return (string);
}
