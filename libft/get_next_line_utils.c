/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:14:15 by sammeuss          #+#    #+#             */
/*   Updated: 2023/01/21 14:48:10 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*double_free(char *s1, char **s2)
{
	free(s1);
	return (free_item(s2));
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	len_backslash_n(char *s, int *read_size, int choice)
{
	int	i;

	i = 0;
	(void)read_size;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	if (choice == 1)
		if (i == ft_strlen_gnl(s))
			return (0);
	return (i);
}

int	ft_fill_save(char **save, int *read_size)
{
	int		i;
	int		x;
	char	*new;

	x = 0;
	i = -1;
	if (!(*save))
		return (0);
	gnl_v2(save, NULL, read_size, &i);
	if ((*save) == 0)
		return (0);
	new = malloc(sizeof(char) * (ft_strlen_gnl(*save) - i) + 1);
	if (!new)
	{
		double_free(*save, &new);
		*save = 0;
		return (-1);
	}
	while ((*save)[i])
			new[x++] = (*save)[i++];
	new[x] = 0;
	free_item(save);
	*save = new;
	return (0);
}

char	*gnl_v2(char **save, char **line, int *read_size, int *i)
{
	if (*i == -1)
	{
		(void)line;
		while ((*save)[(++*i)])
			if ((*save)[*i] == '\n')
				break ;
		if ((*save)[(++*i) - 1] != '\n' && *read_size == 0)
			free_item(save);
	}
	if (*i == 0)
	{
		if (!(*line))
			*save = 0;
		if ((read_size == 0 && !(*save) && !(*line)) || !(*line))
			return (double_free(*line, save));
		if (ft_fill_save(save, read_size) == -1 || *line[0] == 0)
			return (free_item(line));
		return (*line);
	}
	return (NULL);
}
