/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:46:59 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/27 22:50:08 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pip_close_fd(int fd_in, int fd_out)
{
	close(fd_in);
	close(fd_out);
}

void	ft_pip_renew(int pip[2])
{
	ft_pip_close_fd(pip[0], pip[1]);
	pipe(pip);
}

void	ft_pip_wait_children(int i)
{
	int	status;

	while (i-- > 0)
		wait(&status);
}
