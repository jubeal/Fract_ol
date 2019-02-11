/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:17:39 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 14:07:38 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_i(const char *s)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (s[i + j])
	{
		i += j;
		j = 0;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
			i++;
		while (s[i + j] == ' ' || s[i + j] == '\t' || s[i + j] == '\n')
			j++;
	}
	return (i);
}

char		*ft_strtrim(const char *s)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	if (!s)
		return ((char *)0);
	i = get_i(s);
	j = 0;
	if (i == 0)
		return (ft_strdup(""));
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	len = i - j;
	if (!(ret = ft_strnew(sizeof(char) * len)))
		return ((char *)0);
	ret[len] = '\0';
	len = -1;
	while ((j + ++len) != i)
		ret[len] = s[j + len];
	return (ret);
}
