/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:05:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/28 22:06:00 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

int    args_case(t_prs_lst *p)
{
    p->tmp_2->args[p->i] = p->tmp->lexeme;
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

int here_doc_flag(t_prs_lst *p)
{
    p->here_doc_flag = 1;
    if (p->tmp->next)
    {
        if (is_symbol(p->tmp->next->lexeme[0]))
            putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
        p->tmp = p->tmp->next;
    }
    else
    {
        putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
        p->tmp_2->is_exec = NO;
        return (-1);
    } 
    return (0);
}

int here_doc_word(t_prs_lst *p)
{
    p->tmp_2->in_fd = ft_heredoc(p->tmp->lexeme);
    p->here_doc_flag = 0;
    if (p->tmp->next)
    {
        p->tmp = p->tmp->next;
        return (0);
    }
    else
        return (-1);
}

int input_flag_case(t_prs_lst *p)
{
    p->red_in_flag = 1;
    if (p->tmp->next)
    {
        if (is_symbol(p->tmp->next->lexeme[0]))
            putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
        p->tmp = p->tmp->next;
        return(0);
    }
    else
    {
        putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
        return (0);
    } 
}

int input_word_case(t_prs_lst *p)
{
    p->tmp_2->in_fd = open(p->tmp->lexeme, O_RDONLY);
    p->red_in_flag = 0;
    if (p->tmp->next)
    {
        p->tmp = p->tmp->next;
        return (0);
    }
    else
        return (-1);
}