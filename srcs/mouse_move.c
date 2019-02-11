/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:20:46 by jubeal            #+#    #+#             */
/*   Updated: 2019/02/06 14:41:34 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_translate(int x2, int y2, t_fract *first)
{
	if (first->trans_stop == 0)
	{
		mlx_hook(first->win, 6, (1L << 6), mouse_move_hook, first);
		return (0);
	}
	first->tools->x += (x2 - first->win_x / 2) / 4;
	first->tools->y += (y2 - first->win_y / 2) / 4;
	ft_bzero(first->data, first->win_x * first->win_y * 4);
	fractol(first);
	return (0);
}

int			mouse_key(int key, int x, int y, t_fract *first)
{
	(void)x;
	(void)y;
	if (key == 4 || key == 5)
		zoom(key, first);
	if (key == 1 && x >= 0 && y >= 0)
	{
		first->trans_stop != 0 ? first->trans_stop = 0 : first->trans_stop++;
		mlx_hook(first->win, 6, (1L << 6), mouse_translate, first);
	}
	return (0);
}

void		commands(void)
{
	ft_putendl("esc to quit program");
	ft_putendl("arrows to move on the fractol");
	ft_putendl("c to change color patern");
	ft_putendl("< > to move the colors");
	ft_putendl("mouse wheel to zoom on the fractol");
	ft_putendl("rigth click to move on the fractol with the mouse");
	ft_putendl("r to reset the fractol");
}
