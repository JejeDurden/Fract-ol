/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:51:43 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 21:38:29 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void		ft_square_z(t_info *map, float z_r, float z_i)
{
	float	tmp;

	while ((z_r * z_r + z_i * z_i) < 4 && map->i < map->itmax)
	{
		tmp = z_r;
		z_r = fabsf(z_r * z_r - z_i * z_i + map->c_r);
		z_i = fabsf(2 * z_i * tmp + map->c_i);
		map->i++;
	}
}

void			ft_braindraw(t_info *map)
{
	float		z_r;
	float		z_i;

	ft_init_image(map);
	map->y = 0;
	while (map->y < map->window_y)
	{
		map->x = 0;
		while (map->x < map->window_x)
		{
			map->i = 0;
			z_r = 0.003 * map->x / map->zoom + map->x1;
			z_i = 0.003 * map->y / map->zoom + map->y1;
			ft_square_z(map, z_r, z_i);
			ft_set_colors(map);
			ft_pixel_put(map);
			map->x++;
		}
		map->y++;
	}
	ft_destroy_image(map);
}

void			ft_brain_values(t_info *map)
{
	map->x1 = -1.5;
	map->x2 = 1.5;
	map->y1 = -1.5;
	map->y2 = 1.5;
	map->c_r = 0.3;
	map->c_i = 0.01;
	map->window_x = 1000;
	map->window_y = 1000;
	map->itmax = 50;
	map->zoom = 1;
	map->colors = 1;
	map->deform = 1;
}

int				ft_brain(t_info *map)
{
	ft_brain_values(map);
	if (ft_init(map) == -1)
		return (-1);
	ft_braindraw(map);
	mlx_key_hook(map->window, ft_key_event, map);
	mlx_mouse_hook(map->window, ft_mouse_event, map);
	mlx_hook(map->window, MOTION_NOTIFY, PTRMOTIONMASK, ft_mouse_move, map);
	mlx_expose_hook(map->window, ft_expose_hook, map);
	mlx_loop(map->mlx);
	return (1);
}
