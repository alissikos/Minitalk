/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 21:24:37 by aheidy            #+#    #+#             */
/*   Updated: 2021/09/12 17:46:20 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(pid_t nbr, char *str)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < ft_strlen(str))
	{
		j = 0;
		while (j < 7)
		{
			if ((str[i] >> j) & 1)
			{
				if (kill(nbr, SIGUSR1) < -1)
					ft_error("Sigaction error with\
				SIGUSR1 signal to the server.");
			}
			else
			{
				if (kill(nbr, SIGUSR2) < -1)
					ft_error("Sigaction error with\
				SIGUSR2 signal to the server.");
			}
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					nbr;

	if (argc != 3)
		args_error(1);
	nbr = ft_atoi(argv[1]);
	if (!nbr)
		args_error(2);
	send_message(nbr, argv[2]);
	send_message(nbr, "\n");
	return (0);
}
