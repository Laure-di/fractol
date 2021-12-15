/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:16:01 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/11 14:33:13 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	render_fractol(t_data *data)
{
	render_background(&data->img, data->win_size, 0x000000);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	fractal_algo(t_data *data, double x, double y)
{
	double	old_z_real;
	int		i;

	old_z_real = 0;
	i = 0;
	while (data->fractol.z_real * data->fractol.z_real + data->fractol.z_img
		* data->fractol.z_img < 4 && i < data->fractol.iteration_max)
	{
		old_z_real = data->fractol.z_real;
		data->fractol.z_real = data->fractol.z_real * data->fractol.z_real
			- data->fractol.z_img * data->fractol.z_img + data->fractol.c_real;
		data->fractol.z_img = 2 * data->fractol.z_img * old_z_real
			+ data->fractol.c_img;
		i++;
	}
	if (i == data->fractol.iteration_max)
		img_pix_put(&data->img, x, y, create_rgb(0, 0, 0));
	else
		img_pix_put(&data->img, x, y, colors(i));
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->y_min = -2;
	fractol->x_min = -2;
	fractol->c_real = 0;
	fractol->c_img = 0;
	fractol->z_img = 0;
	fractol->z_real = 0;
	fractol->iteration_max = 80;
	fractol->zoom = 200;
	fractol->fractal = &mandelbrot;
}

void	mandelbrot(void *ptr, double y, double x)
{
	t_data	*data;

	data = (t_data *)ptr;
	data->fractol.c_real = x / data->fractol.zoom + data->fractol.x_min;
	data->fractol.c_img = y / data->fractol.zoom + data->fractol.y_min;
	data->fractol.z_real = 0;
	data->fractol.z_img = 0;
	if (data->fractol.type == 1)
		fractal_algo(data, x, y);
	else
		burnship_algo(data, x, y);
}

void	draw(void *ptr)
{
	double		x;
	double		y;
	t_data		*data;

	data = (t_data *)ptr;
	x = 0;
	while (x < data->win_size)
	{
		y = 0;
		while (y < data->win_size)
		{
			data->fractol.fractal(data, y, x);
			y += 1;
		}
		x += 1;
	}
}
