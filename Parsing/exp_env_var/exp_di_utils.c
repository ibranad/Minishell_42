/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_di_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:42:59 by ibnada            #+#    #+#             */
/*   Updated: 2022/07/05 15:43:01 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*t_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;
    int     s1_len;
    int     s2_len;

	join = NULL;
	if (!s1)
        s1_len = 0;
    else
        s1_len = ft_strlen(s1);
    if (!s2)
        s2_len = 0;
    else
        s2_len = ft_strlen(s2);
    if (s1_len > 0 || s2_len > 0)
	    join = malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1_len > 0 && i < s1_len)
		join[j++] = s1[i++];
	i = 0;
	while (s2_len > 0 && i < s2_len)
		join[j++] = s2[i++];
	if (s1_len > 0 || s2_len > 0)
		join[j] = '\0';
	return (join);
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

void print_2d_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        printf("arr[%d]==>>%s<<\n", i, arr[i]);
        i++;
    }
}

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

// int main(int ac, char **av, char **env)
// {
//     char *a;
//     char *b;

//     a = "sh";
//     b = "sh";
//     //printf("%s\n", t_strjoin(a, b));
//     printf("%d\n", is_in_env("LESS", env));
// }
