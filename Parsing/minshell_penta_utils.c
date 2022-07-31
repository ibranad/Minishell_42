/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell_penta_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:54:05 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/31 21:49:01 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//9ad function smiha special char katchecki 3la bash special chars
//add apend ">>" in out_function
 
int arr_len(char **arr)
{
    int i;
    i = 0;

    while(arr[i])
        i++;
    return (i);
}

int illegal_char(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if (str[i] == '\\' || str[i] == ';')
            return (-7);
        else
            i++;
    }
    return (0);
}

int d_quote(char *str)
{
    int i;
    int s_q;
    int d_q;

    i = 0;
    s_q = 0;
    d_q = 0;
    while (str[i])
    {
        if (str[i] == '\'')
            s_q++;
        if (str[i] == '"')
            d_q++;
        i++;
    }
    if ((s_q % 2) == 0)
        return (0);
    else
        return (-1);
    if ((d_q % 2) == 0)
        return (0);
    else
        return(-2);
}

int in_error(char *str)
{
    int i;
    int len;
    char **arr;

    i = 0;
    arr = ft_split(str, ' ');
    len = arr_len(arr);
    while (arr[i] && i < len)
    {
        if (arr[i][0] == '<')
        {
            if (arr[i][1] == '<')
            {
                i++;
                if (arr[i])
                {
                    if (ft_isascii(str[0]) == 1)
                        continue;       
                }
                else
                    return (-3);
            }
            i++;
            if (arr[i])
            {
                if (ft_isascii(str[0]) == 1)
                    i++;
            }
            else
                return (-4);
        }
        i++;
    }
    return (0);
}

int out_errors(char *str)
{
    int i;
    int len;
    char **arr;

    i = 0;
    arr = ft_split(str, ' ');
    len = arr_len(arr);
    while (arr[i] && i < len)
    {
        if (arr[i][0] == '>')
        {
            if (arr[i][1] == '>')
            {
                i++;
                if (arr[i])
                {
                    if (ft_isascii(str[0]) == 1)
                        continue;       
                }
                else
                    return (-5);
            }
            i++;
            if (arr[i])
            {
                if (ft_isascii(str[0]) == 1)
                    i++;
            }
            else
                return (-6);
        }
        i++;
    }
    return (0);
}

int parsing_errors(char *str)
{
    if (!str)
        return(-1);
    else if (ft_isascii(str[0]) == 1 && ft_strlen(str) == 1)
        return(-2);
    else if (d_quote(str) != 0)
        return (-3);
    else if (in_error(str) != 0)
        return (-4);
    else if (out_errors(str) != 0)
        return (-5);
    else if (illegal_char(str) != 0)
        return (-6);
    return (0);
}

int main(void)
{
    printf("%d\n", parsing_errors("echo <"));
}