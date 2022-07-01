#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "Lib/libft.h"
# define CYAN "\033[0;36m"
# define WHITE "\x1B[37m"


typedef struct dollar_sign
{
    int len;
    char *str;
}   t_dol;


// typedef struct returned_data
// {
//     char *cmd_path = "/bin/ls";
//     char **args = {"ls", "-la", NULL};
//     int input_fd = 3;
//     int output_fd = 4;
//     struct returned_data *next = NULL;
// }

char    *get_new_string(char *str);

#endif