/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:43:52 by aheidy            #+#    #+#             */
/*   Updated: 2021/09/12 17:40:39 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(pid_t nbr, char *str)
{
	int		i;
	size_t	j;

	i = 0;
	while (i <= ft_strlen(str))
	{
		j = 0;
		while (j < sizeof(char) * CHAR_BIT)
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
			usleep(1000);
		}
		i++;
	}
}

static void	client_handler(int sig, siginfo_t *siginfo, void *data)
{
	(void)data;
	if (sig == SIGUSR1)
	{
		ft_putstr("Server with PID: ");
		ft_putnbr(siginfo->si_pid);
		ft_putstr(" got your message.\n");
	}
	else
		ft_error("Signal error.");
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	int					nbr;

	if (argc != 3)
		args_error(1);
	nbr = ft_atoi(argv[1]);
	if (!nbr)
		args_error(2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &client_handler;
	if ((sigaction(SIGUSR1, &act, NULL)) < 0)
		ft_error("Message confirmation error.");
	send_message(nbr, argv[2]);
	return (0);
}
