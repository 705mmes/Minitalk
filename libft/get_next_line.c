/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:13:41 by sammeuss          #+#    #+#             */
/*   Updated: 2023/01/21 14:44:40 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_item(char **s)
{
	if (*s)
	{
		free(*s);
		*s = 0;
		return (*s);
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int *read_size, int i)
{
	char	*r;
	int		x;

	x = 0;
	r = NULL;
	if (!s1 && !s2)
		return (free_item(&s1));
	r = malloc(sizeof(char) * (ft_strlen(s1) + (*read_size) + 1));
	if (!r)
		return (free_item(&s1));
	if (s1)
	{
		i--;
		while (s1[++i])
			r[i] = s1[i];
	}
	free(s1);
	while (x < (*read_size))
	{
		r[i] = s2[x];
		i++;
		x++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_read_until_backslash_n(char	*s, int fd, char *save, int *read_size)
{
	int		u;

	u = 0;
	*read_size = read(fd, s, BUFFER_SIZE);
	while (u <= (*read_size))
	{
		if (u == (*read_size))
		{
			save = ft_strjoin_gnl(save, s, read_size, 0);
			*read_size = read(fd, s, BUFFER_SIZE);
			if (*read_size == 0)
				return (save);
			if (*read_size == -1)
				return (free_item(&save));
			u = 0;
		}
		if (s[u] == '\n')
		{
			save = ft_strjoin_gnl(save, s, read_size, 0);
			return (save);
		}
		u++;
	}
	return (save);
}

char	*ft_line(char *save, char *line, int *read_size)
{
	int	i;

	i = 0;
	if (!save)
		return (free_item(&save));
	line = malloc(sizeof(char) * (len_backslash_n(save, read_size, 0) + 1));
	if (!line)
		return (free_item(&save));
	while (save[i])
	{
		line[i] = save[i];
		if (save[i] == '\n')
		{
			line[i + 1] = '\0';
			return (line);
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	char		*line;
	int			read_size;
	int			i;

	i = 0;
	read_size = 0;
	buffer[BUFFER_SIZE] = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (free_item(&save));
	if (len_backslash_n(save, &read_size, 1) > 0)
	{
		line = ft_line(save, line, &read_size);
		if (!line)
			save = 0;
		if (ft_fill_save(&save, &read_size) == -1)
			return (free_item(&line));
		return (line);
	}
	save = ft_read_until_backslash_n(buffer, fd, save, &read_size);
	line = ft_line(save, line, &read_size);
	return (gnl_v2(&save, &line, &read_size, &i));
}
