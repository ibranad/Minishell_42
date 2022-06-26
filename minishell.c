#include "minshell.h"

int s_alloc(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i])
    {
        if((str[i] == '|') || (str[i] == '>') || (str[i] == '<'))
            j++;
        i++;
    }
    return ((i + (j * 2) + 1));
}

char    *get_new_string(char *str)
{
    int i = 0;
    int j = 0;
    char    *line;

    line = malloc(sizeof(char) * s_alloc(str));
    while(str[i])
    {
        if ((str[i] == '|') || (str[i] == '>') || (str[i] == '<'))
        {
            line[j++] = str[i];
            line[j++] = ' ';
        }
        else if((str[i + 1] == '|') || (str[i + 1] == '>') || (str[i + 1] == '<'))
        {
            line[j++] = str[i];
            line[j++] = ' ';
        }
        else
        {
            line[j] = str[i];
            j++;
        }
        i++;
    }
    line[j] = 0;
    return (line);
}



int main(void)
{
    char *str;
    char *line;

    while(1)
    {
        str = readline("minishell$> ");
        add_history(str);
        printf("str is %s\n", str);
        line = get_new_string(str);
    }
}