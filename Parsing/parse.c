#include "../minishell.h"

t_cmdl	*parse(int ac, char **av, t_envl *envl)
{
	char	*cmd_line;
	t_lex	*lexed_cmd_line;
	t_cmdl	*parsed_cmd_line;

	parsed_cmd_line = NULL;
	cmd_line = readline(CYAN "Minishell $> " WHITE);
	add_history(cmd_line);
	lexed_cmd_line = lexer(cmd_line);
	return (parsed_cmd_line);
}