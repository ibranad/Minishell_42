/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/06 08:20:41 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

int	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}


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

void	lex_skip_blanks(t_lex *lex)
{
	while (ft_isblank(lex->c))
		lex_forward(lex);
}
 
