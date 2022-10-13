/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_methods_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:48:25 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/13 18:45:44 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*lex_chardup(t_lex *lex)
{
	char	*copy;

	copy = malloc(sizeof(char) * 2);
	if (!copy)
		malloc_fail();
	copy[0] = lex->c;
	copy[1] = 0;
	return (copy);
}

int	check_chev(char c)
{
	
}