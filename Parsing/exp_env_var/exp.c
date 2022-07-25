/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:42:35 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/25 20:28:14 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exp.h"

// hndle "'$USER'" 
 
char *expand_extra(char *str, char **env)
{
    char **arr;
    char *ar;
    char *a;
    char *b = NULL;
    int i;
    int j;
    int c;

    ar = str_rep(str);
    printf("str rep retuen is :%s\n", ar);
    a = space_add(ar);
    arr = ft_split(a, ' ');
    char_rep(arr, 8, ' ');


    i = 0;
    j = 0;
    c = arr_len(arr);
    print_2d_arr(arr);
    while(arr[i] && i < c)
    {
        if (arr[i][j] == '$')
        {
            if ((arr[i][0] == '$') && (arr[i][1] == ' '))
                b = t_strjoin(b, "$ ");
            else if (if_last_is(arr[i], ' ') == 1 && ft_strlen(arr[i]) > 2)
            {
                arr[i] = char_remove(arr[i], ' ');
                if (is_in_env(&arr[i][1], env) == 1)
                {
                    b = t_strjoin(b, replace_it(arr[i], env));
                    b = t_strjoin(b, " ");
                }
                else
                    b = t_strjoin(b, " ");
            }
            else if (is_in_env(&arr[i][1], env) == 1)
                b = t_strjoin(b, replace_it(arr[i], env));
            else
                b = t_strjoin(b, NULL);
        }
        else if (arr[i][j] == '\"')
        {
            i++;
            printf("lol1\n");
            b = t_strjoin(b, double_quote(arr[i], env));
            i++;
        }
        else if(arr[i][j] == '\'')
        {
            if (arr[i][1] == ' ')
            {
                b = t_strjoin(b, " ");
                i++;
                continue;
            }
            //printf("arr[i][j] is %c, i is %d, j is %d\n", arr[i][1], i , j);
            i++;
            b = t_strjoin(b, arr[i]);
        }
        else
            b = t_strjoin(b, arr[i]);
        i++;
    }
    return (b);
}

char *str_rep(char *str)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    line = malloc(sizeof(char) * ft_strlen(str) + 1);
    while(str[i])
    {
        if(str[i] == ' ')
            line[j] = 8;
        else
            line[j] = str[i];
        i++;
        j++;
    }
    line[j] = 0;
    return (line);
}

char *space_add(char *str)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    printf("%s\n", str);
    line = malloc(sizeof(char) * strlen(str) + (dollar_number(str, '/')) +(dollar_number(str, '.')) +(dollar_number(str, '\"')) + (dollar_number(str, 8) + 1));   
    while (str[i])
    {
        if (str[i] == 8)
        {
            line[j++] = str[i];
            line[j] = ' ';
        }
        else if (str[i] == '$' || ft_isalnum(str[i]) == 0)
        {
            line[j++] = ' ';
            line[j] = str[i];
        }
        else
            line[j] = str[i];
        i++;
        j++;
    }
    line[j] = 0;
    return (line);
}

char **char_rep(char **str, char old, char new)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {

        j = 0;
        while(str[i][j])
        {
            if (str[i][j] == old)
                str[i][j] = new;
            j++;
        }
        i++;
    }
    return (str);
}