/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tetra_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:54:48 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/23 21:08:32 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

/*
*   error handling for these function will in form of return of type struct that containes the two vars
*   one is the string itself, and int variable for error code (0 for sucsess, -1 for failure)
*/

char *single_quote(char *str)
{
    int     i;
    int     j;
    int     a;
    int     len;
    char    *line;
    int count;
    
    i = 0;
    a = 0;
    count = 0;
    len = strlen(str);
    line = malloc(sizeof(char) * (len - 1));
    while (str[i] && i < len)
    {
        if (str[i] == '\'')
        {
            i++;
            count++;
            while (str[i])
            {
                j = i + 1;
                if (str[j] == '\'')
                {
                    count++;
                  line[a] = str[i];
                  a++;
                  break ;
                }
                line[a] = str[i];
                a++;
                i++;
            }
        }
        i++;
    }
    line[a] = '\0';
    if (count < 2)
       return(NULL); 
    return(line);
}

char *double_quote(char *str)
{
    int     i;
    int     j;
    int     a;
    int     len;
    char    *line;
    int count;
    
    i = 0;
    a = 0;
    count = 0;
    len = strlen(str);
    line = malloc(sizeof(char) * (len - 1));
    while (str[i] && i < len)
    {
        if (str[i] == '\"')
        {
            i++;
            count++;
            while (str[i])
            {
                j = i + 1;
                if (str[j] == '\"')
                {
                    count++;
                  line[a] = str[i];
                  a++;
                  break ;
                }
                line[a] = str[i];
                a++;
                i++;
            }
        }
        i++;
    }
    line[a] = '\0';
    if (count < 2)
       return(NULL);
    
    return(line);
}