/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:10:37 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/08 16:51:39 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_fractol *fractol)
{
	fractol->y_min = -2;
	fractol->x_min = -2;
	fractol->zoom = 200;
	fractol->iteration_max = 250;
	fractol->fractal = &julia;
	fractol->c_real = -0.75;
	fractol->c_img = 0.1;
}

void	julia(void *ptr, double y, double x)
{
	t_data	*data;

	data = (t_data *)ptr;
	data->fractol.z_real = x / data->fractol.zoom + data->fractol.x_min;
	data->fractol.z_img = y / data->fractol.zoom + data->fractol.y_min;
	fractal_algo(data, x, y);
}
