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

int	ft_argc_check(int argc)
{
	if (argc < 5)
		ft_err_exit("Argv must be greater than 4.");
	return (1);
}

void	ft_read_here_doc(char *limiter, int pip[2])
{
	char	*line;
	char	*tmp;

	while (1)
	{
		write (1, "> ", 2);
		line = ft_get_next_line(0);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n");
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter) + 1) == 0)
		{
			free(tmp);
			free(line);
			break ;
		}
		ft_putstr_fd (line, pip[1]);
		free (tmp);
		free(line);
	}
}

int	ft_pip_check_here_doc(char **argv, int	pip[2])
{
	int	fd_tmp;

	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		ft_read_here_doc(argv[2], pip);
		close(pip[1]); // Write ends
		return (1);
	}
	fd_tmp = open(argv[1], O_RDONLY);
	if (fd_tmp < 0)
		ft_err_exit ("pipex : %s : file not found");
	else
		pip[0] = fd_tmp;
	return (0);
}
