/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:48:58 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 13:57:40 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char *)0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (unsigned char)c)
			ret = (char *)s + i;
		i++;
	}
	return (ret);
}
