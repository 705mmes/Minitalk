/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:55:00 by smunio            #+#    #+#             */
/*   Updated: 2023/05/09 12:32:41 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "libft/libft.h"

void	char_to_bit(int pid, char str);
void	sigusr(int sig, siginfo_t *info, void *context);
void	error(pid_t pid_client, int *bit, int *i, char *str);
void	nothing(int sig, siginfo_t *info, void *context);
char	*ft_strjoin_char(char *s1, char s2);
void	send_size(int pid, char **argv);
void	get_size(int sig, siginfo_t *info, void *context);

#endif