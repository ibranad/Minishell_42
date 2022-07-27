#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
// #include <readline.h>
// #include <history.h>
# define CYAN "\033[0;36m"
# define WHITE "\x1B[37m"
# include "Libft/libft.h"
# include "exp_env_var/exp.h"
# include "heredoc/heredoc.h"

typedef struct dollar_sign
{
    int len;
    char *str;
}   t_dol;

typedef struct context
{
    char *cmd_path;
    char **args;
    int in_fd;
    int index;
    int out_fd;
    int is_exec;
    struct context *next;
}   t_cont;

typedef struct vt
{
	char	*arr;
	int		s_len;
	int		d_len;
	int		i;
	int		j;
}			t_vt;

// typedef struct returned_data
// {
//     char *cmd_path = "/bin/ls";
//     char **args = {"ls", "-la", NULL};
//     int input_fd = 3;
//     int output_fd = 4;
//     struct returned_data *next = NULL;
// }

int     ft_heredoc(char *lim);
int     arr_len(char **arr);
int     ft_lstsize(t_cont *lst);
int     if_last_is(char *str, char c);
int     is_in_env(char *str, char **env);
char	**get_path(char **env);
char	*get_path_line(char **env);
char    *get_new_string(char *str);
char    *char_remove(char *str, char c);
char	*av_join_acess(char **env, char *av);
char	*slash_av_join(char *src, char c, char *dest);
void    print_2d_arr(char **arr);
void	saj_short(t_vt *v, char *src);
void    post_dollar(t_dol *var, char *str);
void    ft_lstadd_front(t_cont **lst, t_cont *new);
t_cont  *ft_lstnew(int content);

#endif