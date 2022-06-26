#include <stdio.h>
#include <stdlib.h>
#include "minshell.h"

int expand_alloc(char *str)
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

t_dol   post_dollar(char *str)
{
    int     i;
    t_dol   line;

    i = 0;
    line.len = 0;
    while(str[i])
    {
        if (str[i] == '$')
        {
            i++;
            if (ft_isalnum(str[i]) != 0)
            {
                line.str = malloc(sizeof(char) * (expand_alloc(str) + 1));
                while(str[i])
                {
                    line.str[line.len] = str[i];
                    i++;
                    line.len++;
                }
                line.str[line.len] = '\0';
                break;
            }
        }
        i++;
    }
    return(line);
}

char *expand_it(char *str, char **env)
{
    int     i;
    t_dol   var;

    var = post_dollar(str);
    i = 0;
    while(env[i])
    {
        if (ft_strncmp(var.str, env[i], var.len) == 0)
            return(&env[i][var.len]);
        i++;
    }
    return(NULL);
}

int main(int ac, char **av, char **env) {
    (void)ac;
    (void)av;
    (void)env;

    printf("%s\n", expand_it(av[ac - 1], env));
}