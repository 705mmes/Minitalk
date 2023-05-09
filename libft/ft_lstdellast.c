/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:39:16 by smunio            #+#    #+#             */
/*   Updated: 2023/05/02 14:40:34 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdellast(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	if (lst->previous)
		lst->previous->next = 0;
	if (lst)
	{
		lst->next = 0;
		free(lst);
	}
}
