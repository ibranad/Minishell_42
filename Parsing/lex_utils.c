/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:47:34 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/31 10:50:37 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

	// if (empty_string(lex, quote))
int	empty_string(t_lex *lex, char quote)
{
	lex_forward(lex);
	if (lex->c == quote)
		return (1);
	else
		lex_backward(lex);
	return (0);	
}
