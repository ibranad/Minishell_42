/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:58:43 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/28 21:59:26 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int command_arg_case(t_prs_lst *p)
{
    if (p->first_word == 0)
    {
        if (cmd_case(p) == -1)
            return(-1);
    }
    else if (p->first_word != 0)
    if (args_case(p))
            return(-1);
    return (0);
}

int heredoc_case(t_prs_lst *p)
{
    if ((p->tmp->nature == _dchev) && (p->here_doc_flag == 0))
    {
        if (here_doc_flag(p)== -1)
            return(-1);
    }
    if ((p->tmp->nature == _word) && (p->here_doc_flag == 1))
    {
        if (here_doc_word(p) == -1)
            return(-1);
    }
    return (0);
}

int red_in_case(t_prs_lst *p)
{
    if ((p->tmp->nature == _chev) && (p->red_in_flag == 0))
    {
        if (input_flag_case(p) == -1)
            return(-1);  
    }
    if ((p->tmp->nature == _word) && (p->red_in_flag == 1))
        if (input_word_case(p) == -1)
            return(-1);
    return (0);
}

int red_out_case(t_prs_lst *p)
{
    if ((p->tmp->nature == _ichev) && (p->red_out_flag == 0))
    {
        if (output_flag_case(p) == -1)
            return(-1);
    }
    if ((p->tmp->nature == _word) && (p->red_out_flag == 1))
        if (output_word_case(p) == -1)
            return(-1);
    return(0);
}

int apnd_case(t_prs_lst *p)
{
    if ((p->tmp->nature == _dichev) && (p->apnd_flag == 0))
    {
        if (apnd_flag_case(p) == -1)
            return(-1);
    }
    if ((p->tmp->nature == _word) && (p->apnd_flag == 1))
    {
        if (apnd_word_case(p) == -1)
            return(-1);
    }
    return(0);
}