/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:34:23 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/16 21:42:56 by ibnada           ###   ########.fr       */
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

// void ft_lstadd_back(t_cmdl **lst, t_cmdl *node)
// {
//   if((*lst))
//   {
//     if((*lst))
//       while((*lst))
//         (*lst) = (*lst)->next;
//     else
//         (*lst) = node;
    
//   }
// }

t_cmdl *create_parse_lst(int size)
{
    int i;
    t_cmdl *new;
    t_cmdl *lst = 0;

    i = 0;
    while (i < size)
    {
        new = ft_lstadd_new(1);
        ft_lstadd_back(&lst, new);
        i++;
    }
    return (lst);
}

t_cmdl  *ft_lstadd_new(int content)
{
    t_cmdl *new;

    new = malloc(sizeof(t_cmdl));
    new->idx = content;
    new->next = NULL;
    return(new);
}

t_cmdl  *ft_lstadd_back(t_cmdl *lst, t_cmdl *node)
{
    t_cmdl *ptr;
    
    if(!lst)
        return(node);
    else
    {
        ptr = lst;
        while(ptr)
            ptr = ptr->next;
        ptr->next = node;
    }
}

t_cmdl *create_parse_lst(int size)
{
    int i;
    t_cmdl *new;
    t_cmdl *lst;

    i = 0;
    while (i < size)
    {
        new = ft_lst_add_new(1);
        ft_lstadd_back(lst, new);
        i++;
    }
    return (lst);
}
void parse_list(t_cmdl **lst, t_toklist *tok_lst);
{
    
}