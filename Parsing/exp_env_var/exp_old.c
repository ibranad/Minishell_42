/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_old.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:44:16 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/05 15:44:18 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int dollar_number(char *str, char c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == c)
            j++;
        i++;
    }
    return (j);
}

int pd_alloc(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(str[i])
    {
        if (str[i] == '$')
        {
            i++;
            while(str[i])
            {
                j++;
                i++;
            }
            break;
        }
    i++;
    }
    return (j);
}

void   post_dollar(t_dol *var, char *str)
{
    int     i;
    int     size;

    i = 0;
    size = pd_alloc(str) + 2;
    var->len = 0;
    while(str[i])
    {
        if (str[i] == '$')
        {
            i++;
            if (env_pass(&str[i]) != -1)
            {
                var->str = malloc(sizeof(char) * size);
                while(str[i])
                {
                    var->str[var->len] = str[i];
                    i++;
                    var->len++;
                }
                var->str[var->len++] = '=';
                var->str[var->len] = '\0';
                break;
            }
        }
        i++;
    }
}

char *env_var(char *str)
{
    int i;
    int j;
    int start;
    int end;
    char *env_var;
    int len;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (str[i] == '$')
        {
            start = i;
            end = i;
            while (str[i] != ' ')
            {
                i++;
                end++;
            }
            break;
        }
        i++;
    }
    len = (end - start);
    env_var = malloc(sizeof(char) * (len + 1));
    i = 0;
    while(str[start] && i < len)
    {
        env_var[i] = str[start];
        start++;
        i++;
    }
    env_var[i] = '\0';
    return (env_var);
}

int main(int ac, char **av, char **env)
{
    // (void)ac;
    // (void)av;
    // (void)env;
    //expand_extra("lol $USER dfzgzdf$HOME");
    //printf("\n====================\n"); 

    printf("\n%s\n", expand_extra("lol $USER", env));
    //printf("%s\n", expand_it("$LESS", env));
    //while (1);
}

//lol$TERM fzgzdf$ $HOME
//lol $ TERMdfzgzdf /Users/ibnada
//lol TERMdfzgzdf$ $HOME
