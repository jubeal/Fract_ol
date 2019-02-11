/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:36:03 by jubeal            #+#    #+#             */
/*   Updated: 2019/02/08 13:43:53 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		deal_key(int key, t_fract *first)
{
	if (key == 53)
		end_program(first);
	if (key >= 123 && key <= 126)
		translate(first, key);
	if (key == 46 && first->tools->mouse_stop)
		first->tools->mouse_stop = 0;
	else if (key == 46 && !first->tools->mouse_stop)
		first->tools->mouse_stop = 1;
	if (key == 15)
	{
		free(first->tools);
		first->tools = NULL;
		ft_bzero(first->data, first->win_x * first->win_y * 4);
		fractol(first);
	}
	if (key == 43 || key == 47 || key == 8)
		change_color(key, first);
	return (1);
}

void			error(int n)
{
	if (n == 1)
	{
		ft_putstr("usage: ./fractol fractol_type. Enter ");
		ft_putstr("\"./fractol help\" to see all types of fractol\n");
	}
	else if (n == 2)
		ft_putstr("error\n");
	else if (n == 3)
		ft_putstr("error: unknown fractol_type\n");
	else if (n == 4)
	{
		ft_putstr("The differents types of fractol are : ");
		ft_putstr("Mandelbrot, Julia, Zebrure, Tricorne, ");
		ft_putstr("Oscilloscope, Vague\n");
	}
	exit(0);
}

void			fractol_choice(t_fract *first)
{
	if (!ft_strcmp("Mandelbrot", first->av[first->i]))
		first->type = 1;
	else if (!ft_strcmp("Julia", first->av[first->i]))
		first->type = 2;
	else if (!ft_strcmp("Zebrure", first->av[first->i]))
		first->type = 3;
	else if (!ft_strcmp("Tricorne", first->av[first->i]))
		first->type = 4;
	else if (!ft_strcmp("Oscilloscope", first->av[first->i]))
		first->type = 5;
	else if (!ft_strcmp("Vague", first->av[first->i]))
		first->type = 6;
	else if (!ft_strcmp("help", first->av[first->i]))
		error(4);
	else
		error(3);
}

void			fractol(t_fract *first)
{
	if (first->type == 1)
		mandelbrot(first);
	else if (first->type == 2)
		julia(first);
	else if (first->type == 3)
		julia_2(first);
	else if (first->type == 4)
		tricorne(first);
	else if (first->type == 5)
		julia_3(first);
	else if (first->type == 6)
		julia_4(first);
}

int				main(int ac, char **av)
{
	t_fract	*first;

	if (ac == 1)
		error(1);
	if (!init_fract(&first, av))
		error(2);
	fractol_choice(first);
	open_windows(first);
	commands();
	fractol(first);
	mlx_hook(first->win, 2, (1L << 1), deal_key, first);
	mlx_mouse_hook(first->win, mouse_key, first);
	mlx_hook(first->win, 6, (1L << 6), mouse_move_hook, first);
	mlx_loop(first->ptr);
	return (0);
}
