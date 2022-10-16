/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:25 by ibnada            #+#    #+#             */
/*   Updated: 2022/10/16 18:28:54 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Header/minishell.h"


char *expand_var_in_str(t_envl *envl, char *in)
{
    t_exp s;

    struct_init(&s);
    while (in[s.g_i] != '\0')
    {
        if(in[s.g_i] == '<')
            in_here_doc_handle(&s, in);
        if (in[s.g_i] == '$' && !in[s.g_i + 1])
            dollar_only_case(&s, in);
        else if (in[s.g_i] == '$')
            dollar_expanding(envl, &s, in);
        else if (in[s.g_i] == '\"')
            dq_expanding(envl, &s, in);
        else if (in[s.g_i] == '\'')
            sq_expanding(&s, in);
        else
            exp_else(&s, in);
    }
    return (s.out);
}

int check_unrequired_by_subject(char *in)
{
    if (unclosed_quote(in) == 1)
        return(-1);
    return (0);
}

// int main(int ac, char *av[], char *env[])
// {
//     int i;
//     char *str;
    
//     while(1)
//     {
//         str = readline("Minisell $> ");
//         char *ptr = expand_var_in_str(str);
//         printf("->%s\n", ptr);
//         free(ptr);
//         free(str);
//     }
// }
