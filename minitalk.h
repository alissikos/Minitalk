/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aheidy <aheidy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:44:07 by aheidy            #+#    #+#             */
/*   Updated: 2021/09/12 18:37:36 by aheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define SIGUSR1 1
# define SIGUSR2 0
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <signal.h>
# include <sys/types.h>

void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	ft_error(char *str);
void	args_error(int check);

#endif
