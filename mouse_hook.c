/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:04:58 by zkarapet          #+#    #+#             */
/*   Updated: 2022/08/13 12:01:33 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_animation(int x, int y, t_mlx *coord)
{
	coord->zr = map_real_part((double)x, coord->width, -2, 2);
	coord->zi = map_img_part((double)y, coord->height, -2, 2);
	julia(coord, coord->data);
	return (0);
}

void	zoom_in(int x, int y, t_mlx *coord)
{
	coord->r = ((double)x / coord->scale_factor + coord->r)
		- ((double)x / (coord->scale_factor * 1.3));
	coord->i = ((double)y / coord->scale_factor + coord->i)
		- ((double)y / (coord->scale_factor * 1.3));
	coord->scale_factor *= 1.3;
}

void	zoom_out(int x, int y, t_mlx *coord)
{
	coord->r = ((double)x / coord->scale_factor + coord->r)
		- ((double)x / (coord->scale_factor / 1.3));
	coord->i = ((double)y / coord->scale_factor + coord->i)
		- ((double)y / (coord->scale_factor / 1.3));
	coord->scale_factor /= 1.3;
}

int	mouse_hook(int mousecode, int x, int y, t_mlx *coord)
{
	if (mousecode == 5)
		zoom_in(x, y, coord);
	else if (mousecode == 4)
		zoom_out(x, y, coord);
	if (coord->flag == 3)
		mandelbrot(coord, coord->data);
	else if (coord->flag == 1)
		julia(coord, coord->data);
	else if (coord->flag == 2)
		my_fractal(coord, coord->data);
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
