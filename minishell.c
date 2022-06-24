#include "minshell.h"

char    *get_new_string(char *str)
{
    char    *line;
    int i = 0;
    int j = 0;

    while (str[i])
    {
        if((str[i] == '|') || (str[i] == '>') || (str[i] == '<'))
            j++;
        i++;
    }
    line = malloc(sizeof(char) * (i + j));
    i = 0;
    j = 0;
    while(str[i])
    {
        j = i;
        if((str[j++] == '|') || (str[j++] == '>') || (str[j++] == '<'))
        {
            line[i++] = ' ';
            line[i] = str[i];
        }
        else
            line[i] = str[i];
        i++;
    }
    line[i] = 0;
    printf("line is %s", line);
    return (line);
}
int main(void)
{
    char *str;
    char *line;

    str = readline("minishell$> ");
    printf("str is %s\n", str);
    line = get_new_string(str);
    //printf("%s/n", line);
}