/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:37:41 by smunio            #+#    #+#             */
/*   Updated: 2022/11/23 15:22:11 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_indicator(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void	ft_itoa_negativ(int n, int len, char *r)
{
	n *= -1;
	r[0] = '-';
	while (len > 0 || n != 0)
	{
		r[len--] = (n % 10) + '0';
		n = n / 10;
	}
}

static void	ft_itoa_positiv(int n, int len, char *r)
{
	while (len > 0 || n != 0)
	{
		r[--len] = (n % 10) + '0';
		n = n / 10;
	}
}

static int	algo_m(int len, int m)
{
	while (m)
	{
		m = m / 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*r;
	int		i;
	int		m;

	m = n;
	i = 0;
	len = 0;
	if (n < 0)
		m *= -1;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = algo_m(len, m);
	i = len + 1;
	r = malloc(sizeof(char) * len + 1 + sign_indicator(n));
	if (!r)
		return (0);
	r[len + sign_indicator(n)] = '\0';
	if (n < 0)
		ft_itoa_negativ(n, len, r);
	else
		ft_itoa_positiv(n, len, r);
	return (r);
}
