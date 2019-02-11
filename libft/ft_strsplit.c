/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:32:59 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/13 12:57:26 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
			words++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] == c)
			i++;
	}
	return (words);
}

static int	ft_size_words(char const *s, char c, int n)
{
	int		size;

	size = 0;
	while (s[n] && s[n] != c)
	{
		n++;
		size++;
	}
	return (size);
}

static char	*ft_string(char const *s, char *str, char c, int n)
{
	int		x;
	int		size;

	x = 0;
	size = ft_size_words(s, c, n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (x < size)
	{
		str[x] = s[n];
		x++;
		n++;
	}
	str[x] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!s || !c)
		return ((char **)0);
	if (!(str = (char**)malloc(sizeof(*str) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		if (s[n] == c)
			n++;
		else
		{
			str[i] = ft_string(s, str[i], c, n);
			while (s[n] && s[n] != c)
				n++;
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
