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
		exp_env_var/exp_tetra_utils.c\

# -fsanitize=address -g


CC = cc

RM = rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) -g $(LIB) $(RDL) $(SRCS) -o $(NAME)

re :
	$(CC) -g $(LIB) $(RDL) $(SRCS) -o $(NAME)

clean :
	$(RM) $(SRCS)