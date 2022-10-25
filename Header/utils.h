/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibnada <ibnada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:36:48 by obouizga          #+#    #+#             */
/*   Updated: 2022/10/25 21:47:40 by ibnada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef UTILS_H
# define UTILS_H

//* SYS_ERR
void	close_fail();
void	dup2_fail();
void	execve_fail(void);
void	fork_fail(void);
void	malloc_fail(void);
void	pipe_fail(void);
void	_errno(void);
pid_t	ft_fork();
void	identifier_err(char *s);
void	path_unset(char *cmd);
void	_err_cmd_not_found(char *command);
//* FREE UTILS
void	free_db_c(char **strings);
void	free_env(t_envl *envl);
void	free_envl_n(t_envl *node);
//* G_UTILS
void	print_table(char **table);
void	print_list(t_cmdl *list);
int     vector_len(char **vec);
void	putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int     nbrlen(int nbr);
char	*ft_itoa(int n);


#endif