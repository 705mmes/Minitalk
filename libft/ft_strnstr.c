/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:31:30 by smunio            #+#    #+#             */
/*   Updated: 2022/11/26 00:41:51 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		u;

	u = 0;
	i = -1;
	if (!n && !haystack)
		return (0);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[++i] && i < n)
	{
		u = 0;
		while (haystack[i + u] && haystack[i + u] == needle[u] && i + u < n)
			if (needle[++u] == '\0')
				return ((char *)&haystack[i]);
	}
	return (0);
}
