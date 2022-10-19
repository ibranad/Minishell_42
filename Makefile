NAME = minishell

CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
FS = -fsanitize=address 
CC = gcc
RDL = -lreadline
FUNCTIONS =	Execu/builtins/setup.c \
			Parsing/lex_methods.c \
			Parsing/lex_methods_2.c \
			Parsing/tokenize.c \
			Parsing/utils.c \
			Parsing/lexer.c \
			Parsing/heredoc.c \
			Parsing/Expand/exp.c \
			Parsing/Expand/exp_util.c \
			Parsing/Expand/exp_util_2.c \
			Parsing/Expand/exp_util_3.c \
			Parsing/Expand/exp_util_4.c \
			Parsing/Parsing_list/parse_list.c \
			Parsing/Parsing_list/parse_list_utils.c \
			Utils/ascii2.c \
			Utils/env_utils.c \
			Utils/ascii.c \
			Utils/utils.c \
			Utils/utils_2.c \
			Utils/utils_3.c \
			Utils/list_utils.c \
			Utils/sys_err.c \
			Utils/split.c \
			main.c

OBJECTS =  $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(FS) $(RDL) $(OBJECTS) -o $(NAME)
		@echo "minishell CREATED"

clean :
		$(RM) $(OBJECTS)

fclean : clean	
		$(RM) $(NAME)
		@echo "MINISHELL REMOVED"
re : fclean all