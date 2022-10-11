/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:07:31 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/11 16:10:07 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_tok	*form_token(int nature, char *lexeme)
{
	t_tok	*token;

	token = malloc(sizeof(t_tok));
	if (!token)
		malloc_fail();
	token->type;
	token->lexeme = lexeme;
	reutrn (token);
}
