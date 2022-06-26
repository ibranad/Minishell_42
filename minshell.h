#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Lib/libft.h"

typedef struct dollar_sign
{
    int len;
    char *str;
}   t_dol;


#endif