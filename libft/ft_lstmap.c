/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:30:19 by smunio            #+#    #+#             */
/*   Updated: 2023/02/21 12:46:55 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(int), void (*del)(int))
{
	t_stack	*new;
	t_stack	*buff;
	t_stack	*cont;

	if (!lst || !f)
		return (0);
	cont = 0;
	while (lst)
	{
		buff = f(lst->content);
		new = ft_lstnew(buff);
		if (!new)
		{
			free(buff);
			ft_lstclear(&cont, del);
			return (0);
		}
		ft_lstadd_back(&cont, new);
		lst = lst->next;
	}
	return (cont);
}
