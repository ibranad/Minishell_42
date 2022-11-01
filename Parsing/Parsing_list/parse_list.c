/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:34:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/11/01 14:37:53 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../Header/minishell.h"

void    lst_init(t_cmdl **lst)
{
    t_cmdl *tmp;
    int i;

    i = 0;
    tmp = *lst;
    while (tmp)
    {
        tmp->args = 0;
        tmp->builtin = -1;
        tmp->idx = i;
        tmp->in_fd = 0;
        tmp->out_fd = 1;
        tmp->path = 0;
		tmp->is_exec = NO;
        i++;
        tmp = tmp->next;
    }
}

int toklist_size_2alloc(t_toklist *tok_list)
{
    int i;
    t_toklist *tmp;

    i = 0;
    tmp = tok_list;
    while(tmp)
    {
        if(tmp->nature == _pipe)
            i++;
        tmp = tmp->next;
    }
    return(i + 1);
}

void    t_prs_lst_init(t_prs_lst *p, t_toklist *tok_lst, t_envl *envl)
{
    p->i = 0;
    p->size = toklist_size_2alloc(tok_lst);
    p->apnd_flag = 0;
    p->red_in_flag = 0;
    p->out_flag = 0;
    p->red_out_flag = 0;
    p->here_doc_flag = 0;
    p->first_word = 0;
    p->cmd_c = 0;
    p->paths = get_paths(envl);
    p->lst = create_parse_lst(p->size);
    lst_init(&p->lst);
    p->tmp_2 = p->lst;
    p->tmp = tok_lst;
}

int    cmd_case(t_prs_lst *p)
{
    p->tmp_2->is_exec = YES;
    if (p->tmp_2->idx != 0 && p->size > 1)
        p->tmp_2->in_fd = -42; 
    p->tmp_2->builtin = get_builtin(p->tmp->lexeme);
    if (notbuiltin(p->tmp_2))
        p->tmp_2->path = fetch_path(p->tmp->lexeme, p->paths);
    p->cmd_c = cmd_count(p->tmp);
    p->tmp_2->args = malloc(sizeof(char *) * (p->cmd_c + 2));
    p->tmp_2->args[p->i] = p->tmp->lexeme;
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

int parse_list_short(t_prs_lst *p)
{
        if ((p->tmp->nature == _word) && (p->here_doc_flag == 0) 
        && (p->red_in_flag == 0) && (p->red_out_flag == 0) && (p->apnd_flag == 0))
            if (command_arg_case(p) == -1)
                return (-1);
        if (p->tmp->nature == _dchev || p->tmp->nature == _word)
            if (heredoc_case(p) == -1)
                return (-1);
        if (p->tmp->nature == _chev || p->tmp->nature == _word)
            if (red_in_case(p) == -1)
                return (-1);
        if ((p->tmp->nature == _ichev) || (p->tmp->nature == _word))
            if (red_out_case(p) == -1)    
                return (-1);
        if (p->tmp->nature == _dichev || p->tmp->nature == _word)
            if (apnd_case(p) == -1)
                return (-1);
        if (p->tmp->nature == _pipe)
        {
            if (pipe_case(p) == -1)
                return (-1);
            else if (pipe_case(p) == -2)
                return(-2);
        }
    return (0);
}

t_cmdl  *parse_list(t_toklist *tok_lst, t_envl *envl)
{
    t_prs_lst p;
    
    t_prs_lst_init(&p, tok_lst, envl);
    while(p.tmp)
    {
        if ((p.tmp->nature == _word) && (p.here_doc_flag == 0) && 
        (p.red_in_flag == 0) && (p.red_out_flag == 0) && (p.apnd_flag == 0))
            if(command_arg_case(&p) == -1)
                break;
        if (p.tmp->nature == _dchev || p.tmp->nature == _word)
            if (heredoc_case(&p) == -1)
                break;
        if (p.tmp->nature == _chev || p.tmp->nature == _word)
            if (red_in_case(&p) == -1)
                break;
        if ((p.tmp->nature == _ichev) || (p.tmp->nature == _word))
            if (red_out_case(&p) == -1)    
                break;
        if (p.tmp->nature == _dichev || p.tmp->nature == _word)
            if (apnd_case(&p) == -1)
                break;
        if (p.tmp->nature == _pipe)
            if (pipe_case(&p) == -1)
                return(NULL);
    }
    return (p.lst);
}


//-------------------------------------------------------------------------------------
        // if ((p.tmp->nature == _word) && (p.here_doc_flag == 0) 
        // && (p.red_in_flag == 0) && (p.red_out_flag == 0) && (p.apnd_flag == 0))
        //     if(command_arg_case(&p) == -1)
        //         break;
        // if (p.tmp->nature == _dchev || p.tmp->nature == _word)
        //     if (heredoc_case(&p) == -1)
        //         break;
        // if (p.tmp->nature == _chev || p.tmp->nature == _word)
        //     if (red_in_case(&p) == -1)
        //         break;
        // if ((p.tmp->nature == _ichev) || (p.tmp->nature == _word))
        //     if (red_out_case(&p) == -1)    
        //         break;
        // if (p.tmp->nature == _dichev || p.tmp->nature == _word)
        //     if (apnd_case(&p) == -1)
        //         break;
        // if (p.tmp->nature == _pipe)
        // {
        //     if (pipe_case(&p) == -2)
        //         return(NULL);
        //     else if(pipe_case(&p) == -1)
        //         break;
        // }
//-------------------------------------------------------------------------------------
        // if (parse_list_short(&p) == -1)
        //     break;
        // else if (parse_list_short(&p) == -2)
        // {
        //     putstr_fd("Syntax error near unexpected token `newline'\n", 2);
        //     return (NULL);
        // }
//-------------------------------------------------------------------------------------
        // status = parse_list_short(&p);
        // if (status == -1)
        //     break;
        // else if (status == -2)
        // {
        //     putstr_fd("Syntax error near unexpected token `newline'\n", 2);
        //     return (NULL);
        // }
//-------------------------------------prs_lst_working------------------------------------------------

        // if ((p.tmp->nature == _word) && (p.here_doc_flag == 0) 
        // && (p.red_in_flag == 0) && (p.red_out_flag == 0) && (p.apnd_flag == 0))
        //     if(command_arg_case(&p) == -1)
        //         break;
        // if (p.tmp->nature == _dchev || p.tmp->nature == _word)
        //     if (heredoc_case(&p) == -1)
        //         break;
        // if (p.tmp->nature == _chev || p.tmp->nature == _word)
        //     if (red_in_case(&p) == -1)
        //         break;
        // if ((p.tmp->nature == _ichev) || (p.tmp->nature == _word))
        //     if (red_out_case(&p) == -1)    
        //         break;
        // if (p.tmp->nature == _dichev || p.tmp->nature == _word)
        //     if (apnd_case(&p) == -1)
        //         break;
        // if (p.tmp->nature == _pipe)
        //     if (pipe_case(&p) == -1)
        //         break;
//-----------------------------------pars_lst_short--------------------------------------------------
    // if ((p->tmp->nature == _word) && (p->here_doc_flag == 0) 
    // && (p->red_in_flag == 0) && (p->red_out_flag == 0) && (p->apnd_flag == 0))
    //     return (command_arg_case(p));
    // if (p->tmp->nature == _dchev || p->tmp->nature == _word)
    //     return (heredoc_case(p));
    // if (p->tmp->nature == _chev || p->tmp->nature == _word)
    //     return (red_in_case(p) == -1);
    // if ((p->tmp->nature == _ichev) || (p->tmp->nature == _word))
    //     return (red_out_case(p));
    // if (p->tmp->nature == _dichev || p->tmp->nature == _word)
    //     return (apnd_case(p));
    // if (p->tmp->nature == _pipe)
    // {
    //     if (pipe_case(p) == -2)
    //         return (-2);
    //     else if (pipe_case(p) == -1)
    //         return (-1);
    // }
    // return (0);