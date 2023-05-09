/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:15:56 by smunio            #+#    #+#             */
/*   Updated: 2023/03/22 12:05:25 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->previous = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
}
