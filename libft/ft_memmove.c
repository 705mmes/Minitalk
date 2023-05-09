/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:40:54 by smunio            #+#    #+#             */
/*   Updated: 2022/11/21 18:22:46 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	char		*s;
	char		*d;
	size_t		i;

	s = (char *)src;
	d = (char *)dst;
	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	if (dst > src)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
