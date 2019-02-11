/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:35:40 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/12 16:48:21 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*current;

	current = *alst;
	tmp = current->next;
	while (tmp)
	{
		ft_lstdelone(&current, del);
		current = tmp;
		tmp = tmp->next;
	}
	ft_lstdelone(&current, del);
	*alst = NULL;
}
