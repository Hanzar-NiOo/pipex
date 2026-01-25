/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:06:57 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 13:16:31 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	pipe1[2];
	// int	pipe2[2];
	// int	i;
	// int	ft_check_arg;

	ft_argc_check(argc);
	ft_pip_renew(pipe1);
	printf ("%s\n", argv[1]);
	return (0);
}
