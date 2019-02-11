/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:25:05 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/15 12:43:54 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return ((char *)0);
	cpy = ft_strcpy(cpy, str);
	return (cpy);
}
