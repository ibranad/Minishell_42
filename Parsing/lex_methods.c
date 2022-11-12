/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:18:13 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/12 13:03:21 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

char	*lex_gather_lexeme(t_lex *lex)
{
	char	*lexeme;
	char	*string;
	char	*sublexeme;

	lexeme = NULL;
	string = NULL;
	sublexeme = NULL;
	while (!ft_isblank(lex->c) && lex->c && !is_symbol(lex->c))
	{
		if (!is_quote(lex->c))
			lexeme = charjoin(lexeme, lex->c);
		else
		{
			sublexeme = lexeme;
			string = lex_gather_str(lex);
			lexeme = ft_strjoin(sublexeme, string);
			free(string);
		}
		lex_forward(lex);
	}
	lex_backward(lex);
	free(sublexeme);
	return (lexeme);
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
	char	*substring;

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
	char	*substring;
	char	*tmp;

	string = NULL;
	substring = NULL;
	while (lex->c && !ft_isblank(lex->c))
	{
		if (lex->c == '\'')
			substring = gather_single_quoted(lex);
		else if (lex->c == '\"')
			substring = gather_double_quoted(lex);
		else if (!ft_isblank(lex->c) && lex->c)
			substring = gather_till_blank(lex);
		tmp = string;
		string = ft_strjoin(tmp, substring);
		free(tmp);
		free(substring);
	}
	if (ft_isblank(lex->c))
		lex_backward(lex);
	return (string);
}
