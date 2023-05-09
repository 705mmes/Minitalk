/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:24:44 by smunio            #+#    #+#             */
/*   Updated: 2022/11/21 18:24:44 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr((char *)set, s1[0]))
		s1++;
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strrchr((char *)set, s1[i]))
		i--;
	return (ft_substr(s1, 0, (i + 1)));
}
