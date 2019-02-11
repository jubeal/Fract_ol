/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:14:10 by jubeal            #+#    #+#             */
/*   Updated: 2019/02/06 17:02:43 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calcul(t_fract *first, int x, int y, int i)
{
	long double tmp;
	long double zr;
	long double zi;
	long double	ci;
	long double	cr;

	cr = (long double)x / first->tools->zoomx + first->tools->x1;
	ci = (long double)y / first->tools->zoomy + first->tools->y1;
	zr = 0;
	zi = 0;
	while (zr * zr + zi * zi < 4 && i < first->tools->iter_max)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = -2 * zi * tmp + ci;
		i++;
	}
	if (i != first->tools->iter_max)
		pixel_put_img(x - first->tools->x, y - first->tools->y, first,
				set_color(i, first));
}

static void	*pixel_choice(void *data)
{
	int			x;
	int			y;
	int			part;
	t_thread	*threads;

	threads = (t_thread *)data;
	part = threads->first->win_y / 8;
	y = part * threads->idx + threads->first->tools->y;
	while (y < (part * (threads->idx + 1)) + threads->first->tools->y)
	{
		x = threads->first->tools->x;
		while (x < threads->first->win_x + threads->first->tools->x)
		{
			calcul(threads->first, x, y, 0);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}

static void	thread_creator(t_fract *first, t_thread **threads)
{
	int		idx;

	idx = -1;
	while (++idx < 8)
	{
		if (!(threads[idx] = (t_thread *)malloc(sizeof(t_thread))))
			return ;
		threads[idx]->first = first;
		threads[idx]->idx = idx;
		if ((pthread_create(&threads[idx]->thread, NULL, pixel_choice,
						threads[idx])))
			return ;
	}
	idx = -1;
	while (++idx < 8)
	{
		if (pthread_join(threads[idx]->thread, NULL))
			return ;
		free(threads[idx]);
	}
}

void		tricorne(t_fract *first)
{
	t_thread	**threads;

	if (!first->tools)
	{
		init_maths(&first->tools, first);
		first->tools->x1 = -1.3;
		first->tools->x2 = 0.7;
		first->tools->y1 = -1.2;
		first->tools->y2 = 1.2;
		first->tools->iter_max = 150;
	}
	if (!(threads = (t_thread **)malloc(sizeof(t_thread *) * 8)))
		return ;
	thread_creator(first, threads);
	free(threads);
	mlx_put_image_to_window(first->ptr, first->win, first->img, 0, 0);
}
