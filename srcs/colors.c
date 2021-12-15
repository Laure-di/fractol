/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:14:24 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/07 01:48:53 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	mng_colors(int i)
{
	if (i == 9)
		return (create_rgb(211, 236, 248));
	if (i == 10)
		return (create_rgb(241, 233, 191));
	if (i == 11)
		return (create_rgb(248, 201, 95));
	if (i == 12)
		return (create_rgb(255, 170, 0));
	if (i == 13)
		return (create_rgb(204, 128, 0));
	if (i == 14)
		return (create_rgb(153, 87, 0));
	if (i == 15)
		return (create_rgb(106, 52, 3));
	return (0);
}

int	colors(int inter)
{
	int		i;

	i = inter % 16;
	if (i == 0)
		return (create_rgb(66, 30, 15));
	if (i == 1)
		return (create_rgb(25, 7, 26));
	if (i == 2)
		return (create_rgb(9, 1, 47));
	if (i == 3)
		return (create_rgb(4, 4, 73));
	if (i == 4)
		return (create_rgb(0, 7, 100));
	if (i == 5)
		return (create_rgb(12, 44, 138));
	if (i == 6)
		return (create_rgb(24, 82, 177));
	if (i == 7)
		return (create_rgb(57, 125, 209));
	if (i == 8)
		return (create_rgb(134, 181, 229));
	return (mng_colors(i));
}
