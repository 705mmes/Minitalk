/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:41:17 by smunio            #+#    #+#             */
/*   Updated: 2023/02/21 12:47:03 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_stack *lst)
{
	int	nb_elements;

	nb_elements = 1;
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		nb_elements++;
		lst = lst->next;
	}
	return (nb_elements);
}
