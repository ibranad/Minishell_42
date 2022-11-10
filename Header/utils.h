/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:36:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/11/10 14:14:14 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef UTILS_H
# define UTILS_H

//* SYS_ERR
void	close_fail(void);
void	dup2_fail(void);
void	execve_fail(void);
void	fork_fail(void);
void	malloc_fail(void);
void	pipe_fail(void);
pid_t	ft_fork();
void	identifier_err(char *s);
int		stderr_path_unset(char *cmd);
int		stderr_cmd_not_found(char *command);
//* FREE UTILS
int		free_db_c(char **strings);
int		free_db_c_start(char **strings, int start);
void	free_env(t_envl *envl);
void	free_envl_n(t_envl *node);
void	free_cmdl_lst(t_cmdl **lst);
void	free_token_list(t_toklist *tokens);
void	free_cmdl_lst(t_cmdl **lst);
//* G_UTILS
void	print_table(char **table);
void	print_list(t_cmdl *list);
int     vector_len(char **vec);
void	putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int     nbrlen(int nbr);
char	*ft_itoa(int n);
int		is_ther_char(char *s, char c);
int		not_integer(char *s);
void	*ft_calloc(size_t count, size_t size);
#endif