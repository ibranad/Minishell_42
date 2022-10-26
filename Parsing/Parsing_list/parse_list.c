/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:34:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/26 15:27:42 by ibnada           ###   ########.fr       */
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
        tmp->builtin = 0;
        tmp->idx = i;
        tmp->in_fd = 0;
        tmp->out_fd = 1;
        tmp->path = 0;
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

typedef struct prs_lst_st
{
    int         i;
    int         size;
    int         apnd_flag;
    int         red_in_flag;
    int         red_out_flag;
    int         here_doc_flag;
    int         first_word;
    int         cmd_c;
    char        **paths;
    t_cmdl      *lst;
    t_cmdl      *tmp_2;
    t_toklist   *tmp;
    
}       t_prs_lst;



t_cmdl  *parse_list(t_toklist *tok_lst, t_envl *envl)
{
    int         i;
    int         size;
    int         apnd_flag;
    int         red_in_flag;
    int         red_out_flag;
    int         here_doc_flag;
    int         first_word;
    int         cmd_c;
    char        **paths;
    t_cmdl      *lst;
    t_cmdl      *tmp_2;
    t_toklist   *tmp;

    i = 0;
    size = 0;
    first_word = 0;
    red_out_flag = 0;
    here_doc_flag = 0;
    red_in_flag = 0;
    apnd_flag = 0;
    
    cmd_c = 0;
    paths = get_paths(envl);
    size = toklist_size_2alloc(tok_lst);
    lst = create_parse_lst(size);
    lst_init(&lst);
    tmp = tok_lst;
    tmp_2 = lst;
    while(tmp)
    {
        if ((tmp->nature == _word) && (here_doc_flag == 0) 
        && (red_in_flag == 0) && (red_out_flag == 0) && (apnd_flag == 0))
        {
            if (first_word == 0)
            {
                if (tmp_2->idx != 0)
                   tmp_2->in_fd = -42; 
                tmp_2->path = fetch_path(tmp->lexeme, paths);
                tmp_2->builtin = is_builtin(tmp->lexeme);
                cmd_c = cmd_count(tmp);
                tmp_2->args = malloc(sizeof(char *) * (cmd_c + 2));
                tmp_2->args[i] = tmp->lexeme;
                first_word = 1;
                i++;
                if (tmp->next)
                {
                    if (tmp->next->nature != _word)
                    {
                        tmp_2->args[i] = 0;
                        tmp = tmp->next;
                    }
                    else
                        tmp = tmp->next;   
                }
                else
                {
                    tmp_2->args[i] = 0;
                    break;
                }
            }
            else if (first_word != 0)
            {
                tmp_2->args[i] = tmp->lexeme;
                i++;
                if (tmp->next)
                {
                    if (tmp->next->nature != _word)
                    {
                        tmp_2->args[i] = 0;
                        tmp = tmp->next;
                    }
                    else
                        tmp = tmp->next;   
                }
                else
                {
                    tmp_2->args[i] = 0;
                    break;
                }
            }
        }
        if (tmp->nature == _dchev || tmp->nature == _word)
        {
            if ((tmp->nature == _dchev) && (here_doc_flag == 0))
            {
                here_doc_flag = 1;
                if (tmp->next)
                {
                    if (is_symbol(tmp->next->lexeme[0]))
                        putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    tmp = tmp->next;
                }
                else
                {
                    putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    break;
                }   
            }
            if ((tmp->nature == _word) && (here_doc_flag == 1))
            {
                tmp_2->in_fd = ft_heredoc(tmp->lexeme);
                here_doc_flag = 0;
                if (tmp->next)
                    tmp = tmp->next;
                else
                    break;
            }
        }
        if (tmp->nature == _chev || tmp->nature == _word)
        {
            if ((tmp->nature == _chev) && (red_in_flag == 0))
            {
                red_in_flag = 1;
                if (tmp->next)
                {
                    if (is_symbol(tmp->next->lexeme[0]))
                        putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    tmp = tmp->next;
                }
                else
                {
                    putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    break;
                }   
            }
            if ((tmp->nature == _word) && (red_in_flag == 1))
            {
                tmp_2->in_fd = open(tmp->lexeme, O_RDONLY);
                red_in_flag = 0;
                if (tmp->next)
                    tmp = tmp->next;
                else
                    break;
            }
        }
        if ((tmp->nature == _ichev) || (tmp->nature == _word))
        {
            if ((tmp->nature == _ichev) && (red_out_flag == 0))
            {
                red_out_flag = 1;
                 if (tmp->next)
                {
                    if (is_symbol(tmp->next->lexeme[0]))
                        putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    tmp = tmp->next;
                }
                else
                {
                    putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    break;
                }   
            }
            if ((tmp->nature == _word) && (red_out_flag == 1))
            {
                tmp_2->out_fd = open(tmp->lexeme, O_CREAT | O_WRONLY | O_TRUNC, 0777);
                if (tmp_2->in_fd < 0)
                    putstr_fd(strerror(errno), 2);
                red_out_flag = 0;
                if (tmp->next)
                    tmp = tmp->next;
                else
                    break;
            }
        }
        if (tmp->nature == _dichev || tmp->nature == _word)
        {
            if ((tmp->nature == _dichev) && (apnd_flag == 0))
            {
                apnd_flag = 1;
                if (tmp->next)
                {
                    if (is_symbol(tmp->next->lexeme[0]))
                        putstr_fd("Syntax error: unexpected token near `\\n`\n", 2);
                    tmp = tmp->next;
                }
                else
                {
                    printf("Syntax error: unexpected token near `\\n`\n");
                    break;
                }   
            }
            if ((tmp->nature == _word) && (apnd_flag == 1))
            {
                tmp_2->out_fd = open(tmp->lexeme, O_CREAT | O_WRONLY | O_APPEND, 0777);
                if (tmp_2->in_fd < 0)
                    putstr_fd(strerror(errno), 2);
                red_in_flag = 0;
                if (tmp->next)
                    tmp = tmp->next;
                else
                    break;
            }
        }
        if (tmp->nature == _pipe)
        {
            if (!(red_out_flag == 0) && !(apnd_flag == 0))
                tmp_2->out_fd = -42;
            tmp_2->args[i] = 0;
            i = 0;
            if (tmp->next)
            {
                red_out_flag = 0;
                here_doc_flag = 0;
                first_word = 0;
                tmp = tmp->next;
                tmp_2 = tmp_2->next;
            }
            else
                break;
        }
    }
    return (lst);
}
