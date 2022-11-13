/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_7.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:09:04 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/13 10:34:51 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

void	pipe_init(t_prs_lst *p)
{
	p->i = 0;
	p->out_flag = 0;
	p->in_flag = 0;
	p->apnd_flag = 0;
	p->first_word = 0;
	p->red_in_flag = 0;
	p->red_out_flag = 0;
	p->here_doc_flag = 0;
	shell.prs_error = 0;
}