/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:34:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/09 15:39:46 by ibnada           ###   ########.fr       */
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

// int	parse_list_short(t_prs_lst *p)
// {
// 	if ((p->tmp->nature == _word) && (p->here_doc_flag == 0)
// 		&& (p->red_in_flag == 0) && (p->red_out_flag == 0)
// 		&& (p->apnd_flag == 0))
// 		if (command_arg_case(p) == -1)
// 			return (-1);
// 	if (p->tmp->nature == _dchev || p->tmp->nature == _word)
// 		if (heredoc_case(p) == -1)
// 			return (-1);
// 	if (p->tmp->nature == _chev || p->tmp->nature == _word)
// 		if (red_in_case(p) == -1)
// 			return (-1);
// 	if ((p->tmp->nature == _ichev) || (p->tmp->nature == _word))
// 		if (red_out_case(p) == -1)
// 			return (-1);
// 	if (p->tmp->nature == _dichev || p->tmp->nature == _word)
// 		if (apnd_case(p) == -1)
// 			return (-1);
// 	if (p->tmp->nature == _pipe)
// 	{
// 		if (pipe_case(p) == -1)
// 			return (-1);
// 		else if (pipe_case(p) == -2)
// 			return (-2);
// 	}
// 	return (0);
// }
