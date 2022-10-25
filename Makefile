NAME = minishell
MAIN = main.c
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf
FS = -fsanitize=address 
CC = gcc
RDL = -lreadline
LDFLAGS="-L/goinfre/ibnada/homebrew/opt/readline/lib"
CPPFLAGS="-I/goinfre/ibnada/homebrew/opt/readline/include"

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
			Parsing/Parsing_list/parse_list_utils_2.c \
			Parsing/parser.c \
			Utils/ascii2.c \
			Utils/env_utils.c \
			Utils/ascii.c \
			Utils/utils.c \
			Utils/utils_2.c \
			Utils/utils_3.c \
			Utils/utils_4.c \
			Utils/list_utils.c \
			Utils/split.c \
			Execu/exec/execute.c \
			Execu/pipex/manip_cmds.c \
			Execu/pipex/pipex.c \
			Execu/pipex/io.c \
			Execu/signals/signals.c \
			Errors/sys_err.c \
			Errors/errors.c \
			Execu/builtins/cd.c \
			Execu/builtins/echo.c \
			Execu/builtins/env.c \
			Execu/builtins/exit.c \
			Execu/builtins/export.c \
			Execu/builtins/pwd.c \
			Execu/builtins/unset.c \
			Utils/free_utils.c \
			Utils/puts.c \
			$(MAIN)

OBJECTS =  $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(RDL) $(FS) $(LDFLAGS) $(CPPFLAGS) $(OBJECTS) -o $(NAME)
		@echo "minishell CREATED"

clean :
		$(RM) $(OBJECTS)

fclean : clean	
		$(RM) $(NAME)
		@echo "MINISHELL REMOVED"
re : fclean all