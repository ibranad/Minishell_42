/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/14 15:50:49 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/lexer.h"

char	*lex_strdup(t_lex *lex, int n)
{
	char	*copy;
	int		i;
	
	copy = malloc(sizeof(char) * n);
	if (!copy)
		malloc_fail();
	i = 0;
	while (i < n)
	{
		copy[i] = lex->c;
		lex_forward(lex);
		i++;
	}
	copy[i] = 0;
	lex_forward(lex);
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
