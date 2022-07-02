/*=====================================
< Makefile lol cmd | cat > out 

< Makefile lol 
 cat > out 

< red-Inpt 
Makefile infile 
Makefile cmd
lol cmd

cat token 
> red_out 
out outfile
======================================*/

#include "minishell.h"

char    *add_char_end(char *str, char c)
{
    int i;
    char *line;

    i = 0;
    line = malloc(sizeof(char) * ft_strlen(str) + 2);
    while(str[i])
    {
        line[i] = str[i];
        i++;
    }
    line[i++] = c;
    line[i] = 0;
    return(line);
}

int is_in_env(char *str, char **env)
{
    int i;
    int j;

    i = 0;
    str = add_char_end(str, '=');
    //printf("%s\n",str);
    while (env[i])
    {
        if (ft_strncmp(str, env[i], ft_strlen(str)) == 0)
        {
            free(str);
            return (1);
        }
        i++;
    }
    free(str);
    return (0);
}

// int main(int ac, char **av, char **env)
// {
//     char *a;
//     char *b;

//     a = "sh";
//     b = "sh";
//     //printf("%s\n", t_strjoin(a, b));
//     printf("%d\n", is_in_env("LESS", env));
// }


