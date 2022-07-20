//# include "../minishell.h"
# include "gnl/get_next_line.h"
# include <readline/readline.h>
# include <readline/history.h>

/*
* Make a founction that checks for input , and fill the linked list in_fd var
* Make a founction that checks for output , and fill the linked list out_fd var
*
* cc -D BUFFER_SIZE=1 -lreadline heredoc.c gnl/get_next_line.c gnl/get_next_line_utils.c
*/

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while (i < n)
	{
		if (sc1[i] != sc2[i])
			return (sc1[i] - sc2[i]);
		else if (sc1[i] == '\0' || sc2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int ft_heredoc(char *lim)
{
    char *line;
    char c = '\n';
    int pip[2];

    pipe(pip);
    line = readline(">");
    while (ft_strncmp(line, lim, ft_strlen(lim)) || (ft_strlen(line) != ft_strlen(lim)))
    {
        write(pip[1], line, ft_strlen(line));
        write(pip[1], &c, 1);
        line = readline(">");
    }
    return (pip[0]);
}

int main(int ac, char **av)
{
    int fd;
    fd = ft_heredoc(av[ac - 1]);
    int fd2 = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
    //printf("lol");
    //while (get_next_line(fd))
    //printf("%s", get_next_line(fd));
    char c;
    while (read(fd , &c, 1))
    {
        write(fd2, &c, 1);
    }
}