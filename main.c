/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:06:57 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/25 14:39:23 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int	pip1[2];
	int	pip2[2];
	int	i;
	int	here_d;

	ft_argc_check(argc);
	ft_pip_renew(pip1);
	ft_pip_renew(pip2);
	here_d = ft_pip_check_here_doc(argv, pip2);
	i = 0;
	while (i < argc - here_d - 3)
	{
		if (i%2 == 1)
			ft_pip_f_process(argv[i+here_d+2], pip1, pip2, env);
		// else
		// 	ft_pip_s_process(argv[i+here_d+2], pip2, pip1, env);
	}
	printf ("%i\n", here_d);
	printf ("%s\n", argv[1]);
	return (0);
}

// // PIPE Write Test
// int	main(void)
// {
// 	int	pip[2];
// 	char	buf[1024];
// 	int	r;

// 	pipe(pip);

// 	ft_read_here_doc("EOF", pip);

// 	r = read(pip[0], buf, 1023);
// 	buf[r] = '\0';

// 	printf("\n--- PIPE CONTENT ---\n%s", buf);

// 	close(pip[0]);
// }
