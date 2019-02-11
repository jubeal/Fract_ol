/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:38:55 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 12:47:49 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	retlen(int n, int sgn)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	len++;
	if (sgn)
		len++;
	return (len);
}

static char	*for_zero(void)
{
	char	*ret;

	if (!(ret = ft_strnew(1)))
		return ((char *)0);
	ret[0] = '0';
	return (ret);
}

char		*ft_itoa(int n)
{
	size_t	len;
	int		sgn;
	char	*ret;

	if (n == 0)
		return (for_zero());
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(sgn = 0) && n < 0)
		sgn++;
	if (n < 0)
		n *= -1;
	len = retlen(n, sgn);
	if (!(ret = ft_strnew(len)))
		return ((char *)0);
	len--;
	while (n > 0 && (len--))
	{
		ret[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sgn)
		ret[0] = '-';
	ft_strrev(ret);
	return (ret);
}
