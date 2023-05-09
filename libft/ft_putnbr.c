/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:16 by smunio            #+#    #+#             */
/*   Updated: 2023/01/21 14:42:39 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_number_base10(long long nb, int u, int taille)
{
	int	i;

	i = 1;
	if (!u)
		return (-1);
	while (nb > 9 && i++)
		nb /= 10;
	i++;
	return (i + taille);
}

int	ft_putnbr(long long nb, int taille)
{
	static int	u;

	u = 1;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		taille = 0;
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, taille);
	if (u && ft_putchar((nb % 10) + 48) == -1)
		u = 0;
	return (size_number_base10(nb, u, taille));
}
