/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:22:36 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 12:43:26 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sdst;
	unsigned char	*ssrc;

	i = 0;
	sdst = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (sdst > ssrc)
		while (i < n)
		{
			sdst[n - 1] = ssrc[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			sdst[i] = ssrc[i];
			i++;
		}
	return (dest);
}
