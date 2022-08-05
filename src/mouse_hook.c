#include "fractol.h"

void	zoom_in(int x, int y, t_mlx *coord)
{
	coord->r = ((double)x / coord->scale_factor + coord->r) - ((double)x / (coord->scale_factor * 1.3));
	coord->i = ((double)y / coord->scale_factor + coord->i) - ((double)y / (coord->scale_factor * 1.3));
	coord->scale_factor *= 1.3;
}

void	zoom_out(int x, int y, t_mlx *coord)
{
	coord->r = ((double)x / coord->scale_factor + coord->r) - ((double)x / (coord->scale_factor / 1.3));
	coord->i = ((double)y / coord->scale_factor + coord->i) - ((double)y / (coord->scale_factor / 1.3));
    coord->scale_factor /= 1.3;
}

int	mouse_hook(int mousecode, int x, int y, t_mlx *coord)
{
	if (mousecode == 5)
		zoom_in(x, y, coord);
	else if (mousecode == 4)
		zoom_out(x, y, coord);
	mandelbrot(coord, coord->data);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	return (0);
}