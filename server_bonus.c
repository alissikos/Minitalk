/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:43:45 by aheidy            #+#    #+#             */
/*   Updated: 2021/09/12 17:41:01 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_handler(int sig, siginfo_t *siginfo, void *data)
{
	static char	ch;
	static int	i;

	(void)data;
	if (sig == SIGUSR1)
	{
		ch = ch | (1 << i);
		i++;
	}
	else if (sig == SIGUSR2)
		i++;
	if (i == sizeof(char) * CHAR_BIT)
	{
		ft_putchar(ch);
		if (ch == 0)
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR1);
		}
		ch = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				id;

	id = getpid();
	ft_putstr("Server PID is: ");
	ft_putnbr(id);
	ft_putstr("\nServer is ready to recieve your messages\n");
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &server_handler;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_error("Sigaction error in server with SIGUSR1 signal");
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_error("Sigaction error in server with SIGUSR2 signal");
	while (1)
		pause();
	return (0);
}
