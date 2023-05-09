/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:45:04 by smunio            #+#    #+#             */
/*   Updated: 2022/11/20 01:03:32 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat( char *destination, const char *source, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	lendest;

	if (!size)
		return (ft_strlen(source));
	lendest = ft_strlen(destination);
	x = 0;
	i = ft_strlen(destination);
	if (size == 0 || size <= lendest)
		return (size + ft_strlen(source));
	while (source[x] && x < (size - lendest - 1))
	{
		destination[i] = source[x];
		i++;
		x++;
	}
	destination[i] = '\0';
	return (lendest + ft_strlen(source));
}
