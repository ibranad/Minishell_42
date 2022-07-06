#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "Libft/libft.h"
# include "exp_env_var/exp.h"
# define CYAN "\033[0;36m"
# define WHITE "\x1B[37m"


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

char    *get_new_string(char *str);
int is_in_env(char *str, char **env);
char *char_remove(char *str, char c);
int if_last_is(char *str, char c);
void print_2d_arr(char **arr);
void	post_dollar(t_dol *var, char *str);

#endif