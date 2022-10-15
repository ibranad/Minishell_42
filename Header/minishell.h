
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# define WRITE_END 1
# define READ_END 0
# define CYAN "\033[0;36m"
# define WHITE "\x1B[37m"
# define RED_IN '<'
# define RED_OUT '>'



// * INcludeing *.h
# include "lexer.h"
# include  "exp.h"
typedef struct s_cmdl
{
	int				idx;
	char			*path;
	char			**args;
	int				in_fd;
	int				out_fd;
	int				builtin;
	struct s_cmdl	*next;
	
}				t_cmdl;

typedef struct s_envl
{
	char	*key;
	char	*value;
	int		idx;
	struct s_envl	*next;
}				t_envl;

typedef struct s_shell
{
	t_envl	*env;
	int		status;
}				g_shell;

g_shell	shell;

//* SYS_ERR
void	close_fail(int fd);
void	dup2_fail(int fd);
void	execve_fail(void);
void	fork_fail(void);
void	malloc_fail(void);
void	pipe_fail(void);
void	_errno(void);
pid_t	ft_fork();
void	identifier_err(char *s);
//* STR MANIP
char	**split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_isblank(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);



//* FREE UTILS
void	free_db_c(char **strings);
void	free_env(t_envl *envl);
void	free_envl_n(t_envl *node);
//* G_UTILS
void	print_table(char **table);
void	print_list(t_cmdl *list);
int     vector_len(char **vec);
//*ENV UTILS
char	**get_paths(t_envl *envl);
char	*fetch_path(char *cmd, char **paths);


//*PARSING //////////////////
int     ft_lstsize(t_cmdl *lst);
int     if_last_is(char *str, char c);
int     is_in_env(char *str, char **env);
char	**get_paths(t_envl *env);
char	*av_join_acess(char **env, char *av);
char	*expand_it(char *str,char **env);
char	*replace_it(char *str, char **env);
char	*expand_extra(char *str, t_envl *env);
char    *double_quote(char *str, char **env);	
//```````````````````````````````````
char    *get_new_string(char *str);
char    *char_remove(char *str, char c);
char	*slash_av_join(char *src, char c, char *dest);
void    ft_lstadd_front(t_cmdl **lst, t_cmdl *new_l);
void	lstadd_back(t_envl **lst, t_envl *new);
t_envl  *lstnew(char **entry, int idx);
int		env_pass(char *str);
int		pd_alloc(char *str);
int		find_char(char *str, char c);
int		dollar_number(char *str, char c);
char	*str_rep(char *str);
char	*env_var(char *str);
char	*space_add(char *str);
char    *single_quote(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*strjoin_s(char *s1, char *s2);
char	*charjoin(char *s1, char c);
char	*add_char_end(char *str, char c);

char	**char_rep(char **str, char old, char nw);
char    *single_quote(char *str);
int		ft_hd_short(char *line, char *lim, int pip);
int		ft_heredoc(char *delim);

//* EXECUTION ///////////////

//* I/O
void	read_from(int fd);
void	write_to(int fd);
void	read_from_pipe(int *fildes);
void	write_to_pipe(int *fildes);
//* COMMAND RUNNING
void	first_cmd(int *fds, t_cmdl *cmdl, t_envl *env);
void	last_cmd(t_cmdl *cmdl, t_envl *env);
void	mid_cmd(int *fildes, t_cmdl *cmdl, t_envl *env);
void	run_sole_cmd(t_cmdl *cmd, t_envl *env);
//* ENV
int	envl_len(t_envl *envl);
t_envl	*set_env(char **env);
//* ENV LIST
int		envl_size(t_cmdl *lst);
t_envl	*envl_new(char **key_val, int idx);
void	envl_addback(t_envl **lst, t_envl *new_l);
//* BUILTIN
void	_env(t_envl *envl);
void	_pwd(void);
void	_echo(int ac, char **av);
void	_export(char **key_val, t_envl **envl);
void	_unset(char **to_unset,t_envl **envl);
void	change_dir(char *s);
void	disp_export(t_envl **envl);
//* PROC
void	execute(t_cmdl *cmd, g_shell shell);
void	pipex(t_cmdl *cmdl, g_shell shell);
void	wait_all(int *status);
t_cmdl	*get_pipline(void);
t_cmdl	*sole_cmd(char *path, char *opt, int in, int out);


#endif

