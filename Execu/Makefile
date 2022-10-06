NAME = exec

CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
FS = -fsanitize=address -g
CC = gcc

FUNCTIONS = Utils/free_utils.c \
			Utils/lstsize.c \
			Utils/print_table.c \
			Utils/split.c \
			Utils/utils_2.c \
			Utils/list_utils.c \
			Utils/utils.c \
			Utils/sys_err.c \
			pipex/io.c \
			pipex/manip_cmds.c  \
			pipex/pipex.c \
			proc/bparse.c  \
			builtins/cd.c \
			builtins/pwd.c \
			builtins/env.c \
			builtins/export.c \
			builtins/unset.c \
			builtins/echo.c \
			setup.c \
			mainex.c

			
OBJECTS =  $(FUNCTIONS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $(FS) $(OBJECTS) -o $(NAME)
		@echo "Exec CREATED"

clean :
		$(RM) $(OBJECTS)

fclean : clean	
		$(RM) $(NAME)
		@echo "Exec REMOVED"
re : fclean all