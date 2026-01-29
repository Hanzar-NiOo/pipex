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

	// printf("I am in get_paths\n");
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

static char	*ft_get_execve(char *cmd, char **paths)
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
		{
			// printf("This file can be opened!\n");
			// printf("exec = %s\n", exec);
			return (exec);
		}
		idx++;
	}
	if (!exec)
		ft_err_exit ("pipex : command not found");
	return (NULL);
}

static void	ft_pip_execve(char *cmd, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	**paths;

	// printf("I get it Bro!\n");
	paths = ft_get_paths(env);
	// int	idx = 0;
	// while (paths[idx++])
	// 	printf("Path = %s\n", paths[idx]);
	args = ft_split(cmd, ' ');
	// while (*args)
	// 	printf("args = %s\n", *args++);
	// (*args)--;
	args[0] = ft_get_execve(args[0], paths);
	// printf("args[0] = %s\n", args[0]);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	// close(fd_in);
	// close(fd_out);
	execve(args[0], args, env);
}

void	ft_pip_f_process(char *cmd, int pip1[2], int pip2[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_err_exit("fork : Resource temporarily unavailable");
	// printf("pid = %i\n", pid);
	if (pid == 0)
	{
		// printf("I am child process\n");
		// printf("Cmd = %s\n", cmd);
		ft_pip_close_fd(pip1[1], pip2[0]);
		ft_pip_execve(cmd, pip1[0], pip2[1], env);
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
		ft_pip_execve(cmd, pip2[0], pip1[1], env);
	}
	ft_pip_renew(pip2);
}
