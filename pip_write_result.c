/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_write_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:54:42 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/27 23:30:24 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pip_write(char *output_file, int fd_in, int here_d)
{
	int		fd_out;
	int		b_read;
	char	buff[1];

	if (here_d == 1)
	{
		fd_out = open(output_file, O_CREAT | O_RDWR | O_APPEND, 0777);
		if (access(output_file, F_OK) == 0)
			unlink(output_file);
	}
	else
		fd_out = open(output_file, O_CREAT | O_WRONLY, 0777);
	if (fd_in < 0)
		ft_err_exit("pip_write : fd_in error");
	if (fd_out < 0)
		ft_err_exit("pip_write : fd_out error");
	b_read = read(fd_in, buff, sizeof(char));
	while (b_read > 0)
	{
		write (fd_out, &buff, 1);
		b_read = read(fd_in, buff, sizeof(char));
	}
}

void	ft_pip_write_result(int argc, char **argv, int pip1[2], int pip2[2])
{
	int	here_d;

	here_d = 0;
	if (ft_strncmp("here_doc", argv[1], 9))
		here_d = 1;
	if ((argc - here_d) % 2 == 1)
		ft_pip_write(argv[argc -1], pip2[0], here_d);
	else
		ft_pip_write(argv[argc -1], pip1[0], here_d);
}
