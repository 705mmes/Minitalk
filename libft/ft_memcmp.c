/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:24:00 by marvin            #+#    #+#             */
/*   Updated: 2022/11/08 14:24:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	int				i;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	i = 0;
	buffer1 = (unsigned char *) pointer1;
	buffer2 = (unsigned char *) pointer2;
	while (size)
	{
		if (buffer1[i] != buffer2[i])
			return (buffer1[i] - buffer2[i]);
		i++;
		size--;
	}
	return (0);
}

/*int main(void)
{
    int tab1[] = {1, 1};
    int tab2[] = {1, 1};

    if (ft_memcmp(tab1, tab2, sizeof(int) * 2) == 0)
    {
        printf("same\n");
    } 
    else    
        printf("not same\n");
}*/