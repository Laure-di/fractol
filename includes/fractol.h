/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 18:01:24 by lauremass         #+#    #+#             */
/*   Updated: 2021/10/14 18:45:58 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void		*mlx_img;
	char		*adrr;
	int			bpp;
	int			line_len;
	int			endian;

}				t_img;

typedef struct s_fractol
{
	int			type;
	double		c_real;
	double		c_img;
	double		z_real;
	double		z_img;
	double		y_min;
	double		x_min;
	long		iteration_max;
	long		zoom;
	void		(*fractal)(void *, double, double);
}				t_fractol;

typedef struct s_data
{
	int			win_size;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img		img;
	t_fractol	fractol;
}				t_data;

/* Fichier main.c */
int		match_fractol(char *fractol, t_data *data);
int		main(int argc, char **argv);
void	manage_window(t_data *data);
void	launch_window(t_data *data);
void	launch_fractol(t_data *data);
void	escape_fractol(t_data *data);
/* Fichier events.c */
int		handle_scroll(int button, int x, int y, t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	handle_julia(int keysym, t_data *data);
/* Fichier utils.c */
void	img_pix_put(t_img *img, int x, int y, int color);
void	render_background(t_img *img, int size, int color);
void	str_tolower(char *str);
void	print_error(char *error);
/* Fichier error_mng.c */
void	print_help(void);
/* Fichier mandelbrot.c */
int		render_fractol(t_data *data);
void	init_mandelbrot(t_fractol *fractol);
void	draw(void *ptr);
void	mandelbrot(void *ptr, double y, double x);
void	fractal_algo(t_data *data, double x, double y);
/* Fichier julia.c */
void	init_julia(t_fractol *fractol);
void	julia(void *ptr, double y, double x);
/* Fichier colors.c */
int		create_rgb(int r, int g, int b);
int		mng_colors(int i);
int		colors(int inter);
/* Fichier libft*/
void	str_tolower(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_tolower(int c);
/* Fichier burnship */
void	burnship_algo(t_data *data, double x, double y);
#endif
