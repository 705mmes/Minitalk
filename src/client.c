/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:21:09 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/04 14:08:57 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	char_to_bit(int pid, char str)
{
	int	bit;
	int	i;

	i = 8;
	bit = 0;
	while (i > 0)
	{
		bit = str % 2;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR1);
		i--;
		str = str / 2;
	}
}

int	main(int argc, char **argv)
{
	int					pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
