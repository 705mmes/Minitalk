/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:24:12 by smunio            #+#    #+#             */
/*   Updated: 2023/02/21 12:46:34 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}	
}
