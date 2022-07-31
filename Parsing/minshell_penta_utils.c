/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell_penta_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:54:05 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/31 17:14:27 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//9ad function smiha special char katchecki 3la bash special chars
//add apend ">>" in out_function
 
int parsing_errors(char *str)
{
    int     i;
    int     j;
    char    **arr;

    i = 0;
    j = 0;
    if (!str)
        return(-1);
    if (ft_isascii(str[0]) == 1 && ft_strlen(str) == 1)
        return(-2);
    arr = ft_split(str, ' ');
    print_2d_arr(arr);
    while (arr[i])
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
        i = 0;
        while(arr[i])
        {
            if (arr[i][0] == '\\' || arr[i][0] == ';')
                return (-7);
            else
                i++;
        }
    return (0);
}

int double_quote(char *str)
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
    int arr_len;
    char **arr;

    i = 0;
    arr = ft_split(str, ' ')
    arr_len = arr_len(arr);
    while (arr[i] && i < arr_len)
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
    int arr_len;
    char **arr;

    i = 0;
    arr = ft_split(str, ' ')
    arr_len = arr_len(arr);
    while (arr[i] && i < arr_len)
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

int main(void)
{
    printf("%d\n", parsing_errors("echo "));
}