/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:35:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/12 17:39:48 by obouizga         ###   ########.fr       */
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
	e_nat	nature;
	char	*lexeme;
}				t_tok;

typedef struct s_toklist
{
	e_nat				nature;
	char				*lexeme;
	struct s_toklist	*next;
}					t_toklist;

t_lex		*init_lex(char *cmd_line);
void		lex_forward(t_lex *lex);
char		*lex_gather_lexeme(t_lex *lex);
t_toklist	*form_new_token(int	nature, char *lexeme);
t_toklist	*get_tokens_list(t_lex *lex, char *cmd_line);
void		lex_skip_blanks(t_lex *lex);
size_t		get_lexeme_size(t_lex *lex);
char		*lex_gather_string(t_lex *lex, char quote);


#endif