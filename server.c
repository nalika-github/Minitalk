/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:40 by ptungbun          #+#    #+#             */
/*   Updated: 2023/04/09 15:31:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void action (int sig)
{
	static int	bitloc = 0;
	static int	c = 0;

	if (sig == SIGUSR1)
		c = c | (1 << bitloc);
	bitloc = bitloc + 1;
	if (bitloc > 7)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		bitloc = 0;
	}
}

int	main (void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
	return (0);
}
