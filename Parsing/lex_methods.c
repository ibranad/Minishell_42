/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:18:13 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/14 18:55:52 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/lexer.h"

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

void	lex_skip_blanks(t_lex *lex)
{
	while (ft_isblank(lex->c))
		lex_forward(lex);
}
 
// char	*lex_gather_lexeme(t_lex *lex)
// {
// 	char	*lexeme;
// 	int		start;
// 	int		len;
// 	int		i;

// 	len = 0;
// 	start = lex->i;
// 	printf("len : %d\n", len);
// 	while (lex->c && !ft_isblank(lex->c))
// 	{
// 		printf("lex->c : %c", lex->c);
// 		lex_forward(lex);
// 		len++;
// 	}
// 	lexeme = malloc(sizeof(char) * len);
// 	if (!lexeme)
// 		malloc_fail();
// 	i = 0;
// 	while (i < len)
// 		lexeme[i++] = lex->string[start++];
// 	lexeme[i] = 0;
// 	return (lexeme);
// }


char	*lex_gather_lexeme(t_lex *lex)
{
	char	*lexeme;

	lexeme = NULL;
	while (!ft_isblank(lex->c))
	{
		lexeme = charjoin(lexeme, lex->c);
		lex_forward(lex);
	}
	return (lexeme);
}


char	*lex_gather_str(t_lex *lex, char quote)
{
	char	*string;

	string = NULL;
	while (lex->c && lex->c != quote)
	{
		string = ft_strjoin(string, &lex->c);
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

