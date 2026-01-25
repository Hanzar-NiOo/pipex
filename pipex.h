/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:11:33 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 13:25:30 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#include "stdio.h"

void	ft_err_exit(char *err_msg);
int		ft_argc_check(int argc);
void	ft_pip_renew(int pip[2]);
int		ft_pip_check_here_doc(char **argv);

#endif