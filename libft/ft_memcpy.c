/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:30:52 by marvin            #+#    #+#             */
/*   Updated: 2022/11/08 12:30:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy( void *destination, const void *source, size_t size )
{
	char		*buff1;
	char		*buff2;
	size_t		i;

	i = 0;
	buff1 = (char *) destination;
	buff2 = (char *) source;
	if (destination == 0 && source == 0)
		return (destination);
	while (i < size)
	{
		buff1[i] = buff2[i];
		i++;
	}
	return (destination);
}

/*int main(void)
{
    int buff1[] = {705, 55};
    int buff2[] = {706, 54};

    ft_memcpy(buff1, buff2, sizeof(int) * 2);
    printf("%d %d", buff1[0], buff1[1]);

    return(0);
}*/