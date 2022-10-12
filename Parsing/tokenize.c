/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:07:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/12 18:28:15 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/lexer.h"

t_toklist	*form_new_token(int nature, char *lexeme)
{
	t_toklist	*token;

	token = malloc(sizeof(t_toklist));
	if (!token)
		malloc_fail();
	token->lexeme = lexeme;
	token->nature = nature;
	token->next = NULL;
	return (token);
}

t_toklist	*get_tokens_list(t_lex *lex, char *cmd_line)
{
	// while (lex->c)
	// {
	// 	if (ft_isblank(lex->c))
	// 		lex_skip_blanks(lex);
	// 	else if (ft_isalnum(lex->c))
	// 		lex_gather_lexeme(lex);
	// 	else if (lex->c == '\"' || lex->c == '\'')
	// 		lex_gather_string(lex, lex->c);
	// }
	RETURN (NULL);
}