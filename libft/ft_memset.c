/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:49:15 by marvin            #+#    #+#             */
/*   Updated: 2022/11/06 16:49:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t count)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = p;
	while (count)
	{
		tab[i] = (unsigned char) value;
		i++;
		count --;
	}
	return (p);
}

/*int main(void)
{
    int i;
    char buffer[] = "bonjour";

    i = 0;
    ft_memset(buffer, '1', sizeof(char) * 2);
    printf("%c %c %c\n", buffer[0], buffer[1], buffer[2]);

    memset(buffer, '1', sizeof(char) * 2);
    printf("%c %c %c\n", buffer[0], buffer[1], buffer[2]);
    return (0);

}*/