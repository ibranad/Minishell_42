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

char *post_dollar(char *str)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    while(str[i])
    {
        if (str[i] == '$')
        {
            i++;
            if (ft_isalnum(str[i]) != 0)
            {
                line = malloc(sizeof(char) * (expand_alloc(str) + 1));
                while(str[i])
                {
                    line[j] = str[i];
                    i++;
                    j++;
                }
                line[j] = '\0';
                break;
            }
        }
        i++;
    }
    return(line);
}

char *expand_it(char *str, char **env)
{
    (void)ac;
    (void)av;

}

int main(int ac, char **av, char **env) {

  printf("%s\n", get_new_string(">cmd1|cmd2<"));
}