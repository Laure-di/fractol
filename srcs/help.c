/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_mng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:14:48 by lmasson           #+#    #+#             */
/*   Updated: 2021/10/07 17:56:04 by lmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_help(void)
{
	printf("General commands : \n");
	printf("+ : increase iteration\n");
	printf("- : decrease iteration\n");
	printf("arrows : to move inside the image\n");
	printf("ESC : to quit the program\n");
	printf("Julia fractol\n");
	printf("1 : decrease real part\n");
	printf("2 : increase real part\n");
	printf("3 : decrease imaginary part\n");
	printf("4 : increase imaginary part\n");
}
