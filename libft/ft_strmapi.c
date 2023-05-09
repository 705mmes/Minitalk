/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:34:10 by smunio            #+#    #+#             */
/*   Updated: 2022/11/18 19:58:45 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int			i;
	char					*alc;

	i = 0;
	if (!s)
		return (NULL);
	alc = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!alc)
		return (NULL);
	while (s[i])
	{
		alc[i] = (int)(*f)(i, s[i]);
		i++;
	}
	alc[i] = '\0';
	return (alc);
}
