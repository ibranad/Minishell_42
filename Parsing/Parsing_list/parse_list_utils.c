/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:46:41 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/19 19:59:43 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"

t_cmdl  *ft_lstadd_new(int content)
{
    t_cmdl *new;

    new = malloc(sizeof(t_cmdl));
    new->idx = content;
    new->next = 0;
    return(new);
}

t_cmdl    *ft_lstlast(t_cmdl *lst)
{
    t_cmdl    *temp;

    if (!lst)
        return (0);
    temp = lst;
    while (temp -> next)
        temp = temp -> next;
    return (temp);
}

void    ft_lstadd_back(t_cmdl **alst, t_cmdl *new)
{
    t_cmdl    *last;

    if (alst)
    {
        if (*alst)
        {
            last = ft_lstlast(*alst);
            last->next = new;
        }
        else
            *alst = new;
    }
}

t_cmdl *create_parse_lst(int size)
{
    int i;
    t_cmdl *new;
    t_cmdl *lst = 0;

    i = 0;
    while (i < size)
    {
        new = ft_lstadd_new(i);
        ft_lstadd_back(&lst, new);
        i++;
    }
    return (lst);
}

int cmd_count(t_toklist *tmp)
{
    int i;
    t_toklist *p;

    i = 0;
    p = tmp;
    while (p != 0)
    {
        if (is_symbol(p->lexeme[0]))
            break;
        i++;
        p = p->next;
    }
    // if (i == 0)
    //     return(1);
    return(i);
}