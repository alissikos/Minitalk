/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:45:06 by aheidy            #+#    #+#             */
/*   Updated: 2021/09/10 20:45:11 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	exit(0);
}

void	args_error(int check)
{
	if (check == 1)
		ft_error("You must pass server ID and a message!");
	else if (check == 2)
		ft_error("To send a message to the server pass the PID and a message");
}
