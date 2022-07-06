NAME = minishell

CFLAGS = -Wall -Wextra -Werror 

RDL = -lreadline

LIB = Libft/libft.a\

SRCS = minishell.c\
		exp_env_var/exp_di_utils.c\
		minishell_utils.c\
		minishell_di_utils.c\

CC = cc

RM = rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(LIB) $(RDL) $(SRCS) -o $(NAME)

clean :
	$(RM) $(SRCS)