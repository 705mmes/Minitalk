/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:21:09 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/10 14:21:13 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	nothing(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	(void) sig;
}

void	char_to_bit(int pid, char c)
{
	int	bit;
	int	i;

	i = 8;
	bit = 0;
	while (i > 0)
	{
		bit = c % 2;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		i--;
		c = c / 2;
		pause();
		usleep(10);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	s_sigaction;

	i = 0;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	s_sigaction.sa_sigaction = nothing;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (argv[2][i])
		char_to_bit(pid, argv[2][i++]);
	char_to_bit(pid, 0);
	return (0);
}
