/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:25:17 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/07 18:51:05 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	manage_window(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr,
			data->win_size, data->win_size);
	data->img.adrr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, &render_fractol, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_mouse_hook(data->win_ptr, &handle_scroll, data);
	mlx_loop(data->mlx_ptr);
	escape_fractol(data);
}

void	launch_window(t_data *data)
{
	data->win_size = 800;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		print_error("Error : couldn't initialize mlx pointer");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_size,
			data->win_size, "Projet fractol : Laure Masson");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		print_error("Error : couldn't initialize window pointer");
	}
	manage_window(data);
}
