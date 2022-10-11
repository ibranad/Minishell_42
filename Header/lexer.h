/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:35:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/11 11:41:34 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEXER_H
# define LEXER_H
# include <string.h>
# include "minishell.h"

typedef struct s_lex
{
	char	c;
	size_t	i;
	char	*string;
	size_t	str_len;
}				t_lex;

typedef enum
{
	_chev,
	_ichev,
	_pipe,
	_squote,
	_dquote,
	_char,
	_digit,
}	e_nat;

typedef struct s_tok
{
	e_nat	type;
	char	*lexeme;
}				t_tok;

t_lex	*init_lex(char *cmd_line);
void	lex_forward(t_lex *lex);
char	*lex_gather_word(t_lex *lex);
t_tok	*form_token(int	nature, char *lexeme);


#endif