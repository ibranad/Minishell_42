/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:14:41 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/15 18:41:53 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/minishell.h"

void	lstadd_tok(t_toklist **lst, t_toklist *new_token)
{
	t_toklist	*current;

	if (new_token)
	{
		if (*lst)
		{
			current = *lst;
			while (current->next)
				current = current->next;
			current->next = new_token;
		}
		else
			*lst = new_token;
	}
}

void	print_tokens(t_toklist *tokens)
{
	 t_toklist	*curr;

	 curr = tokens;
	 while (curr)
	 {
		printf("(nature: %d, lexeme: %s)\n", curr->nature, curr->lexeme);
		curr = curr->next;
	 }
}