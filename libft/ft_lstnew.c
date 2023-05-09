/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:39:14 by smunio            #+#    #+#             */
/*   Updated: 2023/02/28 08:38:03 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->content = data;
	list->next = 0;
	list->previous = 0;
	return (list);
}
