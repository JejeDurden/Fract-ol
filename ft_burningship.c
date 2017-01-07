/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:55:04 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 16:56:26 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void		ft_burningdraw(t_info *map)
{
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		tmp;

	ft_init_image(map);
	map->y = 0;
	while (map->y < map->window_y)
	{
		map->x = 0;
		while (map->x < map->window_x)
		{
			c_r = 0.003 * map->x / map->zoom + map->x1;
			c_i = 0.003 * map->y / map->zoom + map->y1;
			map->i = 0;
			z_r = 0;
			z_i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && map->i < map->itmax)
			{
				tmp = z_r;
				z_r = fabsf(z_r * z_r - z_i * z_i + c_r);
				z_i = fabsf(2 * z_i * tmp + c_i);
				map->i++;
			}
			ft_set_colors(map);
			ft_pixel_put(map);
			map->x++;
		}
		map->y++;
	}
	ft_destroy_image(map);
}

void		ft_burningship_values(t_info *map)
{
	map->x1 = -2.1;
	map->x2 = 1.2;
	map->y1 = -1.5;
	map->y2 = 1.5;
	map->window_x = 1000;
	map->window_y = 1000;
	map->itmax = 50;
	map->zoom = 1;
	map->colors = 0;
	map->deform = 1;
}

int		ft_burningship(t_info *map)
{
	ft_burningship_values(map);
	if (ft_init(map) == -1)
		return (-1);
	ft_burningdraw(map);
	mlx_key_hook(map->window, ft_key_event, map);
	mlx_mouse_hook(map->window, ft_mouse_event, map);
	mlx_hook(map->window, MOTION_NOTIFY, PTRMOTIONMASK, ft_mouse_move, map);
	mlx_expose_hook(map->window, ft_expose_hook, map);
	mlx_loop(map->mlx);
	return (1);
}

