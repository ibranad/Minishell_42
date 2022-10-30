

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:02:37 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/30 12:00:43 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int output_flag_case(t_prs_lst *p)
{
    p->red_out_flag = 1;
    if (p->tmp->next)
    {
        if (is_symbol(p->tmp->next->lexeme[0]))
            putstr_fd("Syntax error near unexpected token `newline'\n", 2);
        p->tmp = p->tmp->next;
        return(0);
    }
    else
    {
        putstr_fd("Syntax error near unexpected token `newline'\n", 2);
        return(-1);
    } 
}

int output_word_case(t_prs_lst *p)
{
    p->out_flag = 1;
    p->tmp_2->out_fd = open(p->tmp->lexeme, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (p->tmp_2->in_fd < 0)
        putstr_fd(strerror(errno), 2);
    p->red_out_flag = 0;
    if (p->tmp->next)
    {
        p->tmp = p->tmp->next;
        return(0);
    }
    else
        return (-1);
}

int apnd_flag_case(t_prs_lst *p)
{
    p->apnd_flag = 1;
    if (p->tmp->next)
    {
        if (is_symbol(p->tmp->next->lexeme[0]))
            putstr_fd("Syntax error near unexpected token newline\n", 2);
        p->tmp = p->tmp->next;
        return (0);
    }
    else
    {
        putstr_fd("Syntax error near unexpected token newline\n", 2);
        return (-1);
    } 
}
int apnd_word_case(t_prs_lst *p)
{
    p->out_flag = 1;
    p->tmp_2->out_fd = open(p->tmp->lexeme, O_CREAT | O_WRONLY | O_APPEND, 0777);
    if (p->tmp_2->in_fd < 0)
        putstr_fd(strerror(errno), 2);
    p->red_in_flag = 0;
    if (p->tmp->next)
        p->tmp = p->tmp->next;
    else
        return (-1);
    return (0);
}

int pipe_case(t_prs_lst *p)
{
    if (p->out_flag == 0 && (p->size -1 != p->tmp_2->idx))
        p->tmp_2->out_fd = -42;
    //p->tmp_2->args[p->i] = 0;
    if (p->tmp->next)
    {
        if (p->tmp->next->nature == _pipe)
        {
            putstr_fd("Syntax error near unexpected token `newline'\n", 2);
            p->tmp_2->is_exec = NO;
            return (-1);
        }
        p->i = 0;
        p->out_flag = 0;
        p->apnd_flag = 0;
        p->first_word = 0;
        p->red_in_flag = 0;
        p->red_out_flag = 0;
        p->here_doc_flag = 0;
        p->tmp = p->tmp->next;
        p->tmp_2 = p->tmp_2->next;
    }
    else
        return (-1);
    return (0);
}