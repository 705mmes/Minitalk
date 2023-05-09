/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:47:41 by smunio            #+#    #+#             */
/*   Updated: 2022/11/16 23:18:41 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = -1;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cpy)
		return (NULL);
	if (src)
	{
		while (src[++i])
			cpy[i] = src[i];
		cpy[i] = '\0';
	}
	return (cpy);
}
