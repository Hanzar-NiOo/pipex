/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:06:57 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 13:32:03 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	pipe1[2];
	int	pipe2[2];
	// int	i;
	int	here_d;

	ft_argc_check(argc);
	ft_pip_renew(pipe1);
	ft_pip_renew(pipe2);
	here_d = ft_pip_check_here_doc(argv);
	printf ("%i\n", here_d);
	printf ("%s\n", argv[1]);
	return (0);
}
