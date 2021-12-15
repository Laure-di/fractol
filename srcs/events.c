/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:15:24 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/12 12:29:25 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 65362)
		data->fractol.y_min += data->fractol.x_min / data->fractol.zoom;
	if (keysym == 65364)
		data->fractol.y_min -= data->fractol.x_min / data->fractol.zoom;
	if (keysym == 65363)
		data->fractol.x_min -= data->fractol.x_min / data->fractol.zoom;
	if (keysym == 65361)
		data->fractol.x_min += data->fractol.x_min / data->fractol.zoom;
	if (keysym == 65451 || keysym == 61)
		data->fractol.iteration_max += 10;
	if ((keysym == 45 || keysym == 65453) && 20 < data->fractol.iteration_max)
		data->fractol.iteration_max -= 10;
	if (keysym == XK_Escape)
		escape_fractol(data);
	if (data->fractol.type == 2)
		handle_julia(keysym, data);
	return (0);
}

void	handle_julia(int keysym, t_data *data)
{
	if ((keysym == 65436 || keysym == 49) && - 2 < data->fractol.c_real)
		data->fractol.c_real -= 0.1;
	if ((keysym == 65433 || keysym == 50) && data->fractol.c_real < 2)
		data->fractol.c_real += 0.1;
	if ((keysym == 65430 || keysym == 52) && - 2 < data->fractol.c_img)
		data->fractol.c_img -= 0.1;
	if ((keysym == 65437 || keysym == 53) && data->fractol.c_img < 2)
		data->fractol.c_img += 0.1;
}

int	handle_scroll(int button, int x, int y, t_data *data)
{
	double	px;
	double	py;
	double	nx;
	double	ny;

	if (button == 4 || button == 5)
	{
		px = (double)x / data->fractol.zoom + data->fractol.x_min;
		py = (double)y / data->fractol.zoom + data->fractol.y_min;
		if (button == 5)
			data->fractol.zoom *= 1.1;
		if (button == 4 && 200 < data->fractol.zoom)
			data->fractol.zoom /= 1.1;
		nx = (double)x / data->fractol.zoom + data->fractol.x_min;
		ny = (double)y / data->fractol.zoom + data->fractol.y_min;
		data->fractol.x_min -= (nx - px);
		data->fractol.y_min -= (ny - py);
	}
	return (0);
}
