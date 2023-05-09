/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:24:05 by smunio            #+#    #+#             */
/*   Updated: 2023/01/21 14:42:31 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_number(long long nb, int u)
{
	int	i;

	i = 1;
	if (!u)
		return (-1);
	while (nb > 15 && i++)
		nb /= 16;
	return (i);
}

int	size_ptr(unsigned long nb, int u)
{
	int	i;

	i = 1;
	if (!u)
		return (-1);
	while (nb > 15 && i++)
		nb /= 16;
	return (i + 1);
}

int	ft_putnbr_hex(long long nb, char *hex)
{
	static int	u;

	u = 1;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb *= -1;
	}
	if (nb > 15)
		ft_putnbr_hex(nb / 16, hex);
	if (u && ft_putchar(hex[nb % 16]) == -1)
		u = 0;
	return (size_number(nb, u));
}

int	ft_putadr_hex(unsigned long nb, int taille)
{
	char		*hex;
	static int	u;

	u = 1;
	hex = "0123456789abcdef";
	if (taille == -1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		taille = 0;
	}
	if (nb > 15)
		ft_putadr_hex(nb / 16, taille);
	if (u && ft_putchar(hex[nb % 16]) == -1)
		u = 0;
	return (size_ptr(nb, u) + 1);
}
//int	main(void)
//{
//	ft_putnbr_hex(705,);
//
//	return (0);
//}
