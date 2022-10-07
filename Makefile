NAME = minishell

CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
FS = -fsanitize=address -g
CC = gcc
RDL = -lreadline
FUNCTIONS = Execu/Utils/free_utils.c \
			Execu/Utils/lstsize.c \
			Execu/Utils/print_table.c \
			Execu/Utils/split.c \
			Execu/Utils/utils_2.c \
			Execu/Utils/list_utils.c \
			Execu/Utils/utils.c \
			Execu/Utils/sys_err.c \
			Execu/pipex/io.c \
			Execu/pipex/manip_cmds.c  \
			Execu/pipex/pipex.c \
			Execu/proc/bparse.c  \
			Execu/builtins/cd.c \
			Execu/builtins/pwd.c \
			Execu/builtins/env.c \
			Execu/builtins/export.c \
			Execu/builtins/unset.c \
			Execu/builtins/echo.c \
			Execu/setup.c \
			Execu/_exec.c \

			
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