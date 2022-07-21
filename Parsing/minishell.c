#include "minishell.h"

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
            if (str[i] == '$')
                line[j] = str[i];
            else
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

void    ft_ms_init(t_cont *ms)
{
    while(ms)
    {
        ms->args = NULL;
        ms->cmd_path = NULL;
        ms->in_fd = 0;
        ms->out_fd = 1;
        ms->is_exec = 1;
        ms = ms->next;
    }
}

int arr_len(char **arr)
{
    int i;
    i = 0;

    while(arr[i])
        i++;
    return (i);
}

void    create_list(t_cont **ms, int len)
{
    int i;
    t_cont *new;

    i = 0;
    while(i < len)
    {
        new = ft_lstnew(1);
        ft_lstadd_front(ms, new);
        i++;
        printf("i value is %d\n", i);
    }
}

void    struct_fill(t_cont *ms, char **arr, int len, char **env)
{
    if (len > 1)
    {
        
    }
    else
    {
        ms->args = ft_split(arr[0], ' ');
        ms->cmd_path = av_join_acess(env, ms->args[0]);
        ms->in_fd = 0;
        ms->out_fd = 1;
        ms->is_exec = 1;
    }
}

int main(int ac, char **av, char **env)
{
    int i;
    int len;
    char    *str;
    char    *line;
    char    **arr;
    t_cont  *ms = NULL;

    i = 0;
    while(1)
    {
        str = readline(CYAN "Minishell $> " WHITE);
        add_history(str);
        line = get_new_string(str);
        line = expand_extra(line, env);
        printf("---->>%s<<----\n", line);
        // arr = ft_split(line, '|');
        // len = arr_len(arr);
        // print_2d_arr(arr);
        // create_list(&ms, len);
        // ft_ms_init(ms);
        // while(ms)
        // {
        //     printf(">>is_exec %d<<\n", ms->is_exec);
        //     printf(">>input fd%d<<\n", ms->in_fd);

        //     ms = ms->next;
        // }
        //struct_fill(ms, arr, len);
        //printf("line is: %s\n", line);
    }
}