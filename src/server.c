/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:21:07 by sammeuss          #+#    #+#             */
/*   Updated: 2023/05/04 14:10:24 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	error(pid_t pid_client, int *bit, int *i, char *str)
{
	kill(pid_client, SIGUSR1);
	str = NULL;
	*bit = 0;
	*i = 0;
	ft_printf("\n");
	if (str)
		free(str);
}

void	sigusr(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;
	static char	*str = NULL;

	(void) info;
	(void) context;
	if (sig == SIGUSR2)
		i = i | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i < 0 || i > 0x7F)
			error(info->si_pid, &bit, &i, str);
		else
		{
			ft_printf("%c", i);
			// str = ft_strjoin_char(str, i);
		}
		if (i == 0)
		{
			ft_printf("%s", str);
			str = NULL;
			free(str);
		}
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	s_sigaction.sa_sigaction = sigusr;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
	{
		usleep(1);
	}
	return (0);
}
