#include <stdio.h>
#include <stdlib.h>
#include "minshell.h"

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

int env_pass(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (ft_isalnum(str[i]) != 0 || str[i] == '_')
            i++;
        else
            return (-1);
    }
    return (i);
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

char *replace_it(char *str, char **env)
{
    int     i;
    t_dol   var;

    post_dollar(&var, str);
    i = 0;
    while(env[i])
    {
        if (ft_strncmp(var.str, env[i], var.len) == 0)
            return(&env[i][var.len]);
        i++;
    }
    return(NULL);
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

char    *expand_it(char *str,char **env)
{
    char    *old;
    char    *new;
    char    *line;
    int     i;
    int     j;
    int     size;

    i = 0;
    j = 0;
    old = env_var(str);
    new = replace_it(old, env);

    size = ((ft_strlen(str) - ft_strlen(old)) + ft_strlen(new));
    line = malloc(sizeof(char) * (size + 1));
    while (i < size)
    {
        if (str[i] == '$')
        {
            while(new[j])
            {
                line[i] = new[j];
                i++;
                j++;
            }
        }
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    printf("%s\n", expand_it("lol $PWD", env));
}