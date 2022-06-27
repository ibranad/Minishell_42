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

int env_allow_char(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        
    }
}

void   post_dollar(t_dol *var, char *str)
{
    int     i;

    i = 0;
    var->len = 0;
    while(str[i])
    {
        if (str[i] == '$')
        {
            i++;
            if (ft_isalnum(str[i]) != 0 || str[i] == '_')
            {
                var->str = malloc(sizeof(char) * (expand_alloc(str) + 1));
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

char *expand_it(char *str, char **env)
{
    int     i;
    t_dol   var;

    if (!(post_dollar(&var, str)));
        return (NULL);
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

    printf("%s\n", expand_it("lol$_CF", env));
}