/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:15:47 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/12 12:35:49 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	match_fractol(char *fractol, t_data *data)
{
	str_tolower(fractol);
	if (ft_strcmp(fractol, "mandelbrot") == 0)
		return (data->fractol.type = 1);
	if (ft_strcmp(fractol, "julia") == 0)
		return (data->fractol.type = 2);
	if (ft_strcmp(fractol, "burningship") == 0)
		return (data->fractol.type = 3);
	return (0);
}

void	escape_fractol(t_data *data)
{
	if (data->mlx_ptr && data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->mlx_ptr && data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	exit (0);
}

void	launch_fractol(t_data *data)
{
	print_help();
	if (data->fractol.type == 1 || data->fractol.type == 3)
		init_mandelbrot(&data->fractol);
	if (data->fractol.type == 2)
		init_julia(&data->fractol);
	launch_window(data);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2 || match_fractol(argv[1], &data) == 0)
	{
		printf("Error : you must choose an appropriate ");
		printf("fractal set : Julia / Mandelbrot / Burningship");
		exit(1);
	}
	else
		launch_fractol(&data);
	exit (0);
}
