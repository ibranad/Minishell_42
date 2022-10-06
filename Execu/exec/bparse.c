 	#include "../minishell.h"

void	set_cmd(t_cmdl *cmd, char *path, char **args, int ifd, int ofd, t_cmdl *next, int idx)
{
	cmd->idx = idx;
	cmd->path = ft_strdup(path);
	cmd->args = args;
	cmd->in_fd = ifd;
	cmd->out_fd = ofd;
	cmd->next = next;
}

void	print_list(t_cmdl *list)
{
	t_cmdl	*curr = list;
	while (curr)
	{
		printf("idx : %d\n", curr->idx);
		printf("path : %s\n", curr->path);
		printf("args : ");
		print_table(curr->args);
		printf("in_fd : %d\n", curr->in_fd);
		printf("out_fd : %d\n", curr->out_fd);
		printf("\n--------------------\n\n");
		curr = curr->next;
	}
}

t_cmdl  *get_pipline(void)
{
	t_cmdl	*first  = malloc(sizeof(t_cmdl));
	t_cmdl	*second = malloc(sizeof(t_cmdl));
	t_cmdl	*third = malloc(sizeof(t_cmdl));
	t_cmdl	*fourth = malloc(sizeof(t_cmdl));
	t_cmdl	*fifth = malloc(sizeof(t_cmdl));

	// set_cmd(first, "/usr/bin/grep", split("grep ^A", ' '), open("./zsandbox/countries.txt", O_RDONLY), -2, second, 0);
	set_cmd(first, "/usr/bin/grep", split("grep ^A", ' '), 0, -2, second, 0);
	set_cmd(second, "/usr/bin/sort", split("sort -r", ' '), -2, -2, third, 1);
	set_cmd(third, "/usr/bin/head", split("head -10", ' '), -2, -2, fourth, 2);
	set_cmd(fourth, "/usr/bin/uniq", split("uniq -c", ' '), -2, -2, fifth, 3);
	// set_cmd(fifth, "/usr/bin/wc", split("wc", ' '), -2, open("./outfile.txt", O_RDWR |  O_CREAT | O_TRUNC, 0777), NULL, 4);
	set_cmd(fifth, "/usr/bin/wc", split("wc", ' '), -2, 1, NULL, 4);
	return (first);
}

t_cmdl	*sole_cmd(char *path, char *opt, int in, int out)
{
	t_cmdl	*cmd = malloc(sizeof(t_cmdl));
	if (!cmd)
		malloc_fail();
	set_cmd(cmd, path, split(opt, ' '), in, out, NULL, 0);
	return (cmd);
}