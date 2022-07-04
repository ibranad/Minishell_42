#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"

char **char_rep(char **str, char old, char new);

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

    printf("str is %s\n", str);
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

// NEED SOME WORK
/*void expand_extra(char *str, char **env)
{
    int i;
    int j;
    int dc;
    int start;
    char *s;
    char *t;
    char *r;
    char **vars;

    i = 0;
    j = 0;
    dc = dollar_number(str);
    vars = malloc(sizeof(char *) * dc + 1);
    if (dc > 1)
    {

        while (str[i])
        {
            if(str[i] == '$')
            {
                start = i;
                while(str[i])
                {
                    if (ft_isalnum(str[i]) == 0 || str[i] != '$')
                        break;
                    i++;
                }
                vars[j] = ft_substr(str, start, (i - start));
                j++;
            }
        }
    }
}*/

char *str_rep(char *str)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    line = malloc(sizeof(char) * ft_strlen(str) + 1);
    while(str[i])
    {
        if(str[i] == ' ')
            line[j] = 8;
        else
            line[j] = str[i];
        i++;
        j++;
    }
    line[j] = 0;
    return (line);
}

char *space_add(char *str)
{
    int     i;
    int     j;
    char    *line;

    i = 0;
    j = 0;
    line = malloc(sizeof(char) * strlen(str) + (dollar_number(str, 8) + 1));   
    while (str[i])
    {
        if (str[i] == 8)
        {
            line[j++] = str[i];
            line[j] = ' ';
        }
        else if (str[i] == '$')
        {
            line[j++] = ' ';
            line[j] = str[i];
        }
        else
            line[j] = str[i];
        i++;
        j++;
    }
    line[j] = 0;
    return (line);
}

char *expand_extra(char *str, char **env)
{
    char **arr;
    char *ar;
    char *a;
    char *b = NULL;
    int i;
    int j;

    ar = str_rep(str);
    a = space_add(ar);
    arr = ft_split(a, ' ');
    char_rep(arr, 8, ' ');


    i = 0;
    j = 0;
    while(arr[i])
    {
        if (arr[i][j] == '$')
        {
            if (is_in_env(&arr[i][1], env) == 1)
                b = t_strjoin(b, replace_it(arr[i], env));
            else
                b = t_strjoin(b, NULL);
        }
        else
            b = t_strjoin(b, arr[i]);
        i++;
    }
    return (b);
}

void print_2d_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
}
int find_char(char *str, char c)
{
  int i;
  int j;
  
  i = 0;
  j = 0;
  while(str[i])
  {
    if (str[i] == c)
      j++;
  i++;
  }
  return(j);
}

char *char_remove(char *str, char c)
{
  int i;
  char *line;

  i = 0;
  line = malloc(sizeof(char) * (strlen(str) - find_char(str, c)) + 1);
  int j = 0;
  
  while (str[i])
  {
    if (str[i] == c)
    {
      i++;
      if (str[i + 1] == c)
        while (str[i] == c)
          i++;
      line[j] = str[i];
    }
    else
      line[j] = str[i];
    i++;
    j++;
  }
  line[j] = 0;
  return(line);
}

char **char_rep(char **str, char old, char new)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {

        j = 0;
        while(str[i][j])
        {
            if (str[i][j] == old)
                str[i][j] = new;
            j++;
        }
        i++;
    }
    return (str);
}

int if_last_is(char *str, char c)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {
        j = i + 1;
        if (str[j] == '\0' && str[i] == c)
            return (1);
      i++;
    }
    return (0);
}



int main(int ac, char **av, char **env)
{
    // (void)ac;
    // (void)av;
    // (void)env;
    //expand_extra("lol $USER dfzgzdf$HOME");
    //printf("%s\n", 
    printf("%s\n", expand_extra("lol $USER dfzgzdf $HOME", env));
    //printf("%s\n", expand_it("$LESS", env));
}