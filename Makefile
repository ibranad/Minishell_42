NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RDL = -lreadline

LIB = Lib/libft.a\

SRCS = minishell.c\

CC = cc

RM = rm -rf

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(RDL) $(SRCS) -o $(NAME)

clean :
	$(RM) $(SRCS)