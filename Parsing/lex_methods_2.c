/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/25 15:54:36 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"


void	lex_skip_blanks(t_lex *lex)
{
	while (ft_isblank(lex->c))
		lex_forward(lex);
}
 
int	is_symbol(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

char	*lex_gather_lexeme(t_lex *lex)
{
	char	*lexeme;

	lexeme = NULL;
	while (!ft_isblank(lex->c) && lex->c && !is_symbol(lex->c))
	{
		if (!is_quote(lex->c))
			lexeme = charjoin(lexeme, lex->c);
		lex_forward(lex);
	}
	lex_backward(lex);
	return (lexeme);
}

// char	*lex_gather_option(t_lex *lex)
// {
// 	char	*option;
// 	option = NULL;
// 	while (!ft_isblank(lex->c) && lex->c && !is_symbol(lex->c))
// 	{
// 		option = charjoin(option, lex->c);
// 		lex_forward(lex);
// 	}
// 	lex_backward(lex);
// 	return (option);
// }

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
