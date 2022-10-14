NAME = minishell

CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
FS = -fsanitize=address -g
CC = gcc
RDL = -lreadline
FUNCTIONS =	Execu/builtins/setup.c \
			Parsing/lex_methods.c \
			Parsing/lex_methods_2.c \
			Parsing/tokenize.c \
			Parsing/utils.c \
			Parsing/lexer.c \
			Utils/ascii2.c \
			Utils/ascii.c \
			Utils/utils.c \
			Utils/list_utils.c \
			Utils/sys_err.c \
			Utils/split.c \
			main.c

OBJECTS =  $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(RDL) $(FS) $(OBJECTS) -o $(NAME)
		@echo "minishell CREATED"

clean :
		$(RM) $(OBJECTS)

fclean : clean	
		$(RM) $(NAME)
		@echo "MINISHELL REMOVED"
re : fclean all