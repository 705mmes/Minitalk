/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smunio <smunio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:36:22 by smunio            #+#    #+#             */
/*   Updated: 2022/11/23 15:26:59 by smunio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return (0);
}

static int	len_words(char *s, char c, int wordslen)
{
	int	i;

	i = 0;
	wordslen = 0;
	while (s[i])
	{
		if (s[i++] != c)
			wordslen++;
		else
			return (wordslen);
	}
	return (wordslen);
}

static char	*nextword(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (c == 0 && s[0] == 0)
		return (0);
	if (c == 0)
		return (1);
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			while (s[i] && s[i] == c)
				i++;
		}
		if (s[i] == c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbwords;
	int		i;
	int		wordslen;

	if (!s)
		return (0);
	nbwords = count_words(s, c);
	tab = malloc(sizeof(char *) * (nbwords + 1));
	if (!tab)
		return (NULL);
	tab[nbwords] = 0;
	i = 0;
	wordslen = 0;
	while (i < nbwords)
	{
		s += wordslen;
		s = nextword((char *)s, c);
		wordslen = len_words((char *)s, c, wordslen);
		tab[i] = ft_substr(s, 0, wordslen);
		if (!tab[i])
			return (free_all(tab, i - 1));
		i++;
	}
	return (tab);
}

//int main(int argc, char **argv)
//{
//	(void)argc;
//	char **test = ft_split(argv[1], ' ');
//	for(int i = 0; test[i]; i++)
//	{
//		printf("%s\n", test[i]);
//		printf("%s\n", test[++i]);
//	}
//}