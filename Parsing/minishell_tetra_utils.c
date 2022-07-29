/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tetra_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:39:34 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/29 19:24:41 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// <  <   lim   cat
/*
<
<
lim
cat
*/
// wc -l << lim
// wc -l << lim
//cat > $USER/out
//don't forget to handle error return 

void    input_handler(t_cont **p, char **arr)
{
    int i;
    int j;
    int k;
    char **cmd_arr;
    t_cont *tmp;
    
    i = 0;
    j = 0;
    k = 0;
    tmp = (*p);
    cmd_arr = ft_split(arr[i], ' ');
    while (arr[i])
    {
        j = 0;
        k = 0;
        while (cmd_arr[j])
        {
            if (cmd_arr[j][k] == RED_IN)
            {
                j++;
                if (cmd_arr[j][k] == RED_IN)
                {
                    j++;
                    tmp->in_fd = ft_heredoc(cmd_arr[j]);
                }
                else
                    tmp->in_fd = open(cmd_arr[j], O_RDONLY);
            }
            else if (tmp->index != 0)
                tmp->in_fd = -2;
            else
                tmp->in_fd = 0;
            j++;
        }
        i++;
        tmp = tmp->next;
    }
}

void    output_handler(t_cont **p, char **arr)
{
    int i;
    int j;
    int k;
    char **cmd_arr;
    t_cont *tmp;
    
    i = 0;
    j = 0;
    k = 0;
    tmp = (*p);
    cmd_arr = ft_split(arr[i], ' ');
    while (arr[i])
    {
        j = 0;
        while (cmd_arr[j])
        {
            if (cmd_arr[j][k] == RED_OUT)
            {
                j++;
                tmp->out_fd = open(cmd_arr[j], O_CREAT | O_WRONLY | O_TRUNC, 0777);
            }
            else if (tmp->index != 0)
                tmp->in_fd = -2;
            else
                tmp->out_fd = 1;
            j++;
        }
        i++;
        tmp = tmp->next;
    }
}