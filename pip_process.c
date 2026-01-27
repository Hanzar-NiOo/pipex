/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:38:32 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 14:39:10 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pip_exec(char *cmd, int r_ end, int w_end, char **env)
{
	char	*args;
	char	**paths;

	dup2(r_end, STDIN_FILENO);
	dup2(w_end, STDPUT_ERRNO);
	// paths =
	args = ft_split(cmd, " ");
}

void	ft_pip_f_process(char *cmd, int pip1[2], int pip[2], char **env)
{
	int	Pid;

	Pid = fork();
	if (Pid < 0)
		ft_err_exit("fork: Resource temporarily unavailable");
	if (Pid == 1)
	{
		ft_pip_close_fd(pip1[0], pip2[1]);
		ft_pip_exec(cmd, pip1[0], pip2[1], env);
	}
}
