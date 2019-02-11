/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:17:58 by jubeal            #+#    #+#             */
/*   Updated: 2019/02/08 12:49:46 by jubeal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "get_next_line.h"

typedef struct		s_maths
{
	long double		iter_max;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	int				i;
	long double		zoomx;
	long double		zoomy;
	int				x;
	int				y;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	int				mouse_x;
	int				mouse_y;
	int				mouse_stop;
}					t_maths;

typedef struct		s_fract
{
	int				type;
	int				win_x;
	int				win_y;
	void			*ptr;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				color_value;
	int				r;
	int				g;
	int				b;
	int				i;
	char			**av;
	int				trans_stop;
	t_maths			*tools;
}					t_fract;

typedef struct		s_thread
{
	pthread_t		thread;
	int				idx;
	t_fract			*first;
}					t_thread;

void				mandelbrot(t_fract *first);
int					init_fract(t_fract **first, char **av);
void				open_windows(t_fract *first);
void				init_maths(t_maths **tools, t_fract *first);
void				pixel_put_img(int x, int y, t_fract *curent, int color);
int					set_color(int i, t_fract *first);
void				translate(t_fract *first, int key);
void				fractol(t_fract *first);
int					zoom(int key, t_fract *first);
void				julia(t_fract *first);
void				julia_2(t_fract *first);
int					mouse_move_hook(int x, int y, t_fract *first);
void				end_program(t_fract *first);
void				fractol_choice(t_fract *first);
int					mouse_key(int key, int x, int y, t_fract *first);
void				change_color(int key, t_fract *first);
void				commands(void);
void				tricorne(t_fract *first);
void				julia_3(t_fract *first);
void				julia_4(t_fract *first);
#endif
