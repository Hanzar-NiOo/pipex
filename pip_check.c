/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:38:32 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 13:41:11 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_argc_check(int argc)
{
	if (argc < 5)
		ft_err_exit("Argv must be greater than 4.");
	return (1);
}

int	ft_pip_check_here_doc(char **argv)
{
	int	fd_tmp;

	fd_tmp = open(argv[1], O_RDONLY);
	if (fd_tmp < 0)
	{
		if (ft_strncmp("here_doc", argv[1], 9) == 0)
		{
			printf ("Thiis is here_doc mode\n");
			return (1);
		}
		else
			ft_err_exit ("pipex : %s : file not found");
	}
	return (0);
}
