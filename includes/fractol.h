/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:37:20 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 22:06:55 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define PTRMOTIONMASK (1L<<6)
# define MOTION_NOTIFY 6

typedef struct		s_info
{
	void	*mlx;
	void	*window;
	void	*image;
	int		window_x;
	int		window_y;
	int		red;
	int		green;
	int		blue;
	char	*data;
	int		zoom;
	int		x;
	int		y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		itmax;
	char	c;
	int		i;
	int		colors;
	int		deform;
}					t_info;

int					ft_fractol(t_info *map, char *param);
int					ft_julia(t_info *map);
void				ft_julia_values(t_info *map);
int					ft_mandelbrot(t_info *map);
void				ft_mandelbrot_values(t_info *map);
int					ft_init(t_info *map);
int					ft_key_event(int keycode, t_info *map);
int					ft_expose_hook(t_info *map);
void				ft_mandeldraw(t_info *map);
void				ft_juliadraw(t_info *map);
void				ft_init_image(t_info *map);
void				ft_destroy_image(t_info *map);
void				ft_set_colors(t_info *map);
void				ft_pixel_put(t_info *map);
int					ft_mouse_event(int button, int x, int y, t_info *map);
int					ft_mouse_move(int x, int y, t_info *map);
void				ft_init_val(t_info *map);
void				ft_burningdraw(t_info *map);
int					ft_burningship(t_info *map);
void				ft_burningship_values(t_info *map);
int					ft_frog(t_info *map);
void				ft_frogdraw(t_info *map);
void				ft_frog_values(t_info *map);
void				ft_black(t_info *map);
void				ft_light_green(t_info *map);
void				ft_light_blue(t_info *map);
void				ft_pink(t_info *map);
void				ft_white(t_info *map);
void				ft_red(t_info *map);
void				ft_blue(t_info *map);
void				ft_orange(t_info *map);
void				ft_yellow(t_info *map);
void				ft_light_grey(t_info *map);
void				ft_colors_0(t_info *map);
void				ft_colors_1(t_info *map);
void				ft_colors_2(t_info *map);
void				ft_gradient_weird(t_info *map);
void				ft_degradient_blue(t_info *map);
void				ft_gradient_blue(t_info *map);
void				ft_braindraw(t_info *map);
void				ft_brain_values(t_info *map);
int					ft_brain(t_info *map);
void				ft_stardraw(t_info *map);
void				ft_star_values(t_info *map);
int					ft_star(t_info *map);

#endif
