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
		#Libft/ft_strlen.c\
		Libft/ft_split.c\
		Libft/ft_isalnum.c\
		Libft/ft_strncmp.c\
		Libft/ft_strlcpy.c\#



CC = gcc

RM = rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(SRCS) $(RDL) $(LIB) -o $(NAME)

re :
	$(CC) $(LIB) $(RDL) $(SRCS) -o $(NAME)

clean :
	$(RM) $(SRCS)