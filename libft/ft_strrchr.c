/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:34:50 by marvin            #+#    #+#             */
/*   Updated: 2022/11/04 17:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int tofind)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0 || s[i] == '\0')
	{
		if (s[i] == (char)tofind)
			return (s += i);
		i--;
	}
	return (0);
}

/*int main(void)
{
    printf("%s", ft_strrchr("ma biate", 'a'));

    return (0);
}*/
