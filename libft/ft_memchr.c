/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:58:45 by marvin            #+#    #+#             */
/*   Updated: 2022/11/08 16:58:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size )
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char *)memoryBlock;
	while (size)
	{
		if (buffer[i] == (char)searchedChar)
			return (&buffer[i]);
		i++;
		size--;
	}
	return (0);
}

/*int	main(void)
{
	int	buff[] = {700, 5};

	if (ft_memchr(buff, 4, sizeof(int) * 2) != NULL)
	{
		printf("Trouvé\n");
	}
	else
		printf("Pas trouvé\n");
	return (0);
}*/