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

static char	**ft_get_paths(char **env)
{
	char	**paths;
	char	*tmp;
	int		idx;

	idx = 0;
	paths = NULL;
	while (env[idx])
	{
		if (ft_strncmp("PATH=", env[idx], 5) == 0)
		{
			tmp = ft_strtrim(env[idx], "PATH=");
			paths = ft_split(tmp, ':');
			break ;
		}
		idx++;
	}
	if (!paths)
		ft_err_exit ("env : paths not found");
	return (paths);
}

static char	*ft_get_exec(char *cmd, char **paths)
{
	char	*exec;
	char	*tmp;
	int		idx;

	if (ft_strncmp(cmd, "./", 2) == 0)
		return (ft_strdup(cmd));
	idx = 0;
	while (paths[idx])
	{
		tmp = ft_strjoin(paths[idx], "/");
		exec = ft_strjoin(tmp, cmd);
		if (access(ft_strjoin(tmp, cmd), F_OK) == 0)
			return (exec);
		idx++;
	}
	if (!exec)
		ft_err_exit ("pipex : command not found");
	return (NULL);
}

static void	ft_pip_exec(char *cmd, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	**paths;

	args = NULL;
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	paths = ft_get_paths(env);
	args = ft_split(cmd, ' ');
	args[0] = ft_get_exec(args[0], paths);
	execve(args[0], args, env);
}

void	ft_pip_f_process(char *cmd, int pip1[2], int pip2[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_err_exit("fork: Resource temporarily unavailable");
	if (pid == 1)
	{
		ft_pip_close_fd(pip1[1], pip2[0]);
		ft_pip_exec(cmd, pip1[0], pip2[1], env);
	}
	ft_pip_renew(pip1);
}

void	ft_pip_s_process(char *cmd, int pip1[2], int pip2[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_err_exit("fork: Resource temporarily unavailable");
	if (pid == 1)
	{
		ft_pip_close_fd(pip1[0], pip2[1]);
		ft_pip_exec(cmd, pip2[0], pip1[1], env);
	}
	ft_pip_renew(pip2);
}
