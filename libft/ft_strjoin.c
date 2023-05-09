/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:00:25 by smunio            #+#    #+#             */
/*   Updated: 2022/11/20 00:55:49 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!s1)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		r[i] = s2[x];
		i++;
		x++;
	}
	r[i] = '\0';
	return (r);
}
