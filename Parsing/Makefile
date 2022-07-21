NAME = minishell

CFLAGS = -Wall -Wextra -Werror 

RDL = -lreadline

LIB = Libft/libft.a\

SRCS = minishell.c\
		minishell_utils.c\
		minishell_di_utils.c\
		exp_env_var/exp.c\
		exp_env_var/exp_di_utils.c\
		exp_env_var/exp_tri_utils.c\
		exp_env_var/exp_old.c\
		exp_env_var/exp_utils.c\
		heredoc/heredoc.c\



CC = cc

RM = rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(LIB) $(RDL) $(SRCS) -o $(NAME)

re :
	$(CC) $(LIB) $(RDL) $(SRCS) -o $(NAME)

clean :
	$(RM) $(SRCS)