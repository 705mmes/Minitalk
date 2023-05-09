/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:43:20 by smunio            #+#    #+#             */
/*   Updated: 2023/03/03 12:25:15 by sammeuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack	**lst, t_stack	*new)
{
	new->next = *lst;
	*lst = new;
	(*lst)->previous = 0;
}
