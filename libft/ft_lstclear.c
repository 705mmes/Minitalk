/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:17:31 by smunio            #+#    #+#             */
/*   Updated: 2023/02/21 12:46:22 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*buff;

	if (!lst || !del)
		return ;
	while (*lst && lst)
	{
		buff = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buff;
	}
}
