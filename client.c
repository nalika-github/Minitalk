/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:12 by ptungbun          #+#    #+#             */
/*   Updated: 2023/04/09 15:12:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

static void	sendsignal(int s_pid, char *str)
{
	int	i;
	int	n_bit;

	i = 0;
	while (str[i])
	{
		n_bit = 0;
		while (n_bit < 8)
		{
			if (str[i] & 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			str[i] = str[i] >> 1;
			n_bit++;
			usleep(100);
		}
		i++;
	}
}

int	main (int argc, char **argv)
{
	int		s_pid;
	char	*str;

	if (argc != 3)
	{
		ft_putstr_fd("invalid input\n", 1);
		return (0);
	}
	s_pid = ft_atoi(argv[1]);
	str = argv[2];
	sendsignal(s_pid, str);
	return (0);
}
