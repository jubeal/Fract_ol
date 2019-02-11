/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:54:22 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/13 14:46:49 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *chr)
{
	int		i;
	int		j;

	i = 0;
	if (chr[0] == '\0')
		return ((char *)src);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == chr[j] || chr[j] == '\0')
		{
			if (chr[j] == '\0')
				return ((char *)src + i);
			j++;
		}
		i++;
	}
	return ((char *)0);
}
