/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:33:12 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 14:04:35 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s)
		return ((char *)0);
	if (!(ret = ft_strnew(sizeof(char) * (len))))
		return ((char *)0);
	ret[len] = '\0';
	while (i < len && ret)
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
