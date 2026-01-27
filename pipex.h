/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:11:33 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 14:36:33 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#include "stdio.h"

void	ft_err_exit(char *err_msg);
int		ft_argc_check(int argc);
void	ft_pip_renew(int pip[2]);
int		ft_pip_check_here_doc(char **argv, int	pip[2]);
void	ft_read_here_doc(char *limiter, int pip[2]);
char	*ft_get_next_line(int fd);
void	ft_pip_f_process(char *cmd, int pip1[2], int pip[2], char **env);

#endif