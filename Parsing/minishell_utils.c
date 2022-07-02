#include "minishell.h"

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

// int main()
// {
//     char *a;
//     char *b;

// 	// a = "hello";
// 	// b = "world";
//     printf("%s", t_strjoin(b, a));    
// }