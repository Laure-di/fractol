/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:36:08 by lauremass         #+#    #+#             */
/*   Updated: 2021/10/11 14:30:17 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burnship_algo(t_data *data, double x, double y)
{
	double	old_z_real;
	int		i;

	old_z_real = 0;
	i = 0;
	while (data->fractol.z_real * data->fractol.z_real + data->fractol.z_img
		* data->fractol.z_img < 4 && i < data->fractol.iteration_max)
	{
		old_z_real = data->fractol.z_real;
		data->fractol.z_real = fabs(data->fractol.z_real * data->fractol.z_real
				- data->fractol.z_img * data->fractol.z_img
				+ data->fractol.c_real);
		data->fractol.z_img = fabs(2 * data->fractol.z_img * old_z_real
				+ data->fractol.c_img);
		i++;
	}
	if (i == data->fractol.iteration_max)
		img_pix_put(&data->img, x, y, create_rgb(0, 0, 0));
	else
		img_pix_put(&data->img, x, y, colors(i));
}
