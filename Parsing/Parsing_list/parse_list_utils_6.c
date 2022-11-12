/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_6.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:17:09 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/12 20:06:16 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	parse_list_short(t_prs_lst *p)
{
	while (p->tmp)
	{
		if (shell.prs_error == 1)
		{
			break;
			return;
		}
		if ((p->tmp->nature == _word) && (p->here_doc_flag == 0)
			&& (p->red_in_flag == 0) && (p->red_out_flag == 0)
			&& (p->apnd_flag == 0))
			if (command_arg_case(p) == -1)
				break ;
		if (p->tmp->nature == _dchev || p->tmp->nature == _word)
			if (heredoc_case(p) == -1)
				break ;
		if (p->tmp->nature == _chev || p->tmp->nature == _word)
			if (red_in_case(p) == -1)
				break ;
		if ((p->tmp->nature == _ichev) || (p->tmp->nature == _word))
			if (red_out_case(p) == -1)
				break ;
		if (p->tmp->nature == _dichev || p->tmp->nature == _word)
			if (apnd_case(p) == -1)
				break ;
		if (p->tmp->nature == _pipe)
			if (pipe_case(p) == -1)
				break ;
	}
	// printf("hello\n");
	// print_parsing_lst(p->lst);
	// echo test1 > out test2 test3
}

t_cmdl	*parse_list(t_toklist *tok_lst, t_envl *envl)
{
	t_prs_lst	p;

	t_prs_lst_init(&p, tok_lst, envl);
	parse_list_short(&p);
	if (shell.prs_error == 1)
	{
		free_cmdl_lst(&p.lst);
		free_db_c(p.paths);
		return (NULL);
	}
	free_db_c(p.paths);
	return (p.lst);
}