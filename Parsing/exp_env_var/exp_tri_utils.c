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

