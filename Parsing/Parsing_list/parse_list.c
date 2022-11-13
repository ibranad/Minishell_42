/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:34:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 17:53:29 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int	cmd_case(t_prs_lst *p)
{
	p->tmp_2->builtin = get_builtin(p->tmp->lexeme);
	if (notbuiltin(p->tmp_2))
		p->tmp_2->path = fetch_path(p->tmp->lexeme, p->paths);
	p->cmd_c = cmd_count(p->tmp);
	p->tmp_2->args = malloc(sizeof(char *) * (p->cmd_c + 2));
	p->tmp_2->args[p->i] = ft_strdup(p->tmp->lexeme);
	p->first_word = 1;
	p->i++;
	if (p->tmp->next)
	{
		if (p->tmp->next->nature != _word)
		{
			p->tmp_2->args[p->i] = 0;
			p->tmp = p->tmp->next;
		}
		else
			p->tmp = p->tmp->next;
	}
	else
	{
		p->tmp_2->args[p->i] = 0;
		return (-1);
	}
	return (0);
}

/*
cmd_case() :lines removed for norm purposes
	// if (p->tmp_2->idx != 0 && p->size > 1)
	// 	p->tmp_2->in_fd = -42;
*/
