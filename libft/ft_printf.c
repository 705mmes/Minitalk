/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:30:28 by smunio            #+#    #+#             */
/*   Updated: 2023/05/03 13:34:57 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	traitement_indicateurs(int i, const char *s, va_list args)
{
	int	size;

	size = -1;
	if (s[i] == 'c')
		size = ft_putchar(va_arg(args, int));
	else if (s[i] == 's')
		size = ft_putstr(va_arg(args, char *));
	else if (s[i] == 'i' || s[i] == 'd')
		size = ft_putnbr(va_arg(args, int), size);
	else if (s[i] == 'u')
		size = ft_putnbr(va_arg(args, unsigned int), size);
	else if (s[i] == 'x')
		size = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s[i] == 'p')
		size = ft_putadr_hex(va_arg(args, unsigned long), size);
	else if (s[i] == 'X')
		size = ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s[i] == '%')
		size = ft_putchar('%');
	if (size == -1)
		size = -2147483648;
	return (size);
}

int	ft_printf(const char	*s, ...)
{
	va_list		args;
	int			size;
	int			i;

	size = 0;
	i = -1;
	if (!s)
		return (0);
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%')
			size += traitement_indicateurs(++i, s, args);
		else
			size += ft_putchar2(s[i]);
		if (size < 0)
			return (-1);
	}
	va_end(args);
	return (size);
}
