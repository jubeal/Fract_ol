/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:54:21 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 14:06:04 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (!s1 || !s2)
		return ((char *)0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ret = ft_strnew(i + j)))
		return ((char *)0);
	i = 0;
	j = 0;
	while (s1[i] && ret)
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] && ret)
	{
		ret[i + j] = s2[j];
		j++;
	}
	if (ret)
		ret[i + j] = '\0';
	return (ret);
}
