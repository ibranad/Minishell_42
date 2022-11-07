/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:05:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/07 17:02:20 by ibnada           ###   ########.fr       */
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
            error_printing();
        p->tmp = p->tmp->next;
    }
    else
    {
        error_printing();
        return (-1);
    } 
    return (0);
}

int here_doc_word(t_prs_lst *p)
{
    p->tmp_2->in_fd = ft_heredoc(p->tmp->lexeme);
    p->here_doc_flag = 0;
    p->in_flag = 1;
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
            error_printing();
        p->tmp = p->tmp->next;
        return(0);
    }
    else
    {
        error_printing();
        return (-1);
    } 
}

int input_word_case(t_prs_lst *p)
{
    p->tmp_2->in_fd = open(p->tmp->lexeme, O_RDONLY);
    p->in_flag = 1;
    if(p->tmp_2->in_fd < 0)
    {
        putstr_fd(strerror(errno), 2);
        putstr_fd("\n", 2);
        return (-1);
    }
    p->red_in_flag = 0;
    if (p->tmp->next)
    {
        p->tmp = p->tmp->next;
        return (0);
    }
    else
        return (-1);
}