/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:11:57 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/12 13:05:14 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

t_toklist	*lexer(char *cmd_line)
{
	t_lex		*lex;
	t_toklist	*tokens;

	lex = init_lex(cmd_line);
	tokens = get_tokens_list(lex);
	free(lex);
	return (tokens);
}
