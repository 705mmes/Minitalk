/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 02:01:55 by marvin            #+#    #+#             */
/*   Updated: 2022/11/04 02:01:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int tofind)
{
	int	i;

	i = 0;
	while (s[i] != '\0' || s[i] == '\0')
	{
		if (s[i] == (char)tofind)
			return (&s[i]);
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*int main(void)
{
    printf("%s", ft_strchr("ma bite", 'y'));
}*/
