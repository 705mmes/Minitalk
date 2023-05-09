/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:00:46 by smunio            #+#    #+#             */
/*   Updated: 2022/11/17 02:06:29 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*buff;

	buff = malloc(size * count);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (size * count));
	return (buff);
}
