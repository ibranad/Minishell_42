/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:25:04 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/02 18:07:47 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# define WRITE_END 1
# define READ_END 0
# define YES 1
# define NO 0
# define EXISTING 1
# define UNEXISTING 0
# define PIPELINE 1
# define SOLE 0

typedef enum e_built
{
	_echo_ = 1,
	_cd_,
	_pwd_,
	_export_,
	_unset_,
	_env_,
	_exit_,
}	t_builtin;

typedef enum e_valid
{
	_builtin_ = 1,
	_unset_path_,
	_command_not_found_,
}	t_validity;
//* I/O
void	read_from(int fd);
void	write_to(int fd);
void	read_from_pipe(int *fildes);
void	write_to_pipe(int *fildes);
int		ft_heredoc(char *delim);
//* COMMAND RUNNING
void	first_cmd(int *fds, t_cmdl *cmdl, int validity, char **env);
void	last_cmd(t_cmdl *cmdl, int validity, char **env);
void	mid_cmd(int *fildes, t_cmdl *cmdl, int validity, char **env);
void	run_sole_cmd(t_cmdl *cmd, char **env, int pf);
void	run(t_cmdl *cmd, int pf, char **env);
//* ENV
int		envl_len(t_envl *envl);
t_envl	*set_env(char **env);
void 	**set_builtin_arr(void);
char	**get_paths(t_envl *envl);
char	*fetch_path(char *cmd, char **paths);
char	*strjoin_s(char *s1, char *s2);
//* ENV LIST
t_envl	*lstnew(char *key, char *value);
int		envl_size(t_cmdl *lst);
void	lstadd_back(t_envl **lst, t_envl *new);
t_envl	*envl_new(char **key_val, int idx);
void	envl_addback(t_envl **lst, t_envl *new_l);
void	set_variable(char *key, char *value, t_envl **envl);
//* BUILTIN
void	_env(t_envl *envl);
void	_pwd(void);
void	_echo(int ac, char **av);
void	_export(char **key_val, t_envl **envl);
void	_unset(char **to_unset,t_envl **envl);
void	__exit(void);
void	change_dir(char *s, t_envl **envl);
void	disp_export(t_envl **envl);
int		isbuiltin(t_cmdl *cmd);
int		notbuiltin(t_cmdl *cmd);
void	run_builtin(t_cmdl *cmd, int cmdline_type);

//* PROC
int		cmdline_size(t_cmdl *lst);
void	pipex(t_cmdl *cmdl, char **env);
void	wait_all(void);
t_cmdl	*get_pipline(void);
t_cmdl	*sole_cmd(char *path, char *opt, int in, int out);
void	ft_execve(t_cmdl *cmd, char **env);
//*VALIDITY
int		command_validity(t_cmdl *command);
void	check_path(t_envl *envl);


#endif