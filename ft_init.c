/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:37:21 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 16:18:58 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_init(t_info *map)
{
	if (!(map->mlx = mlx_init()))
		return (-1);
	if (map->c == 'm')
		map->window = mlx_new_window(map->mlx, map->window_x, map->window_y, 
										"Mandelbrot");
	if (map->c == 'j')
		map->window = mlx_new_window(map->mlx, map->window_x, map->window_y, 
										"Julia");
	if (map->c == 'b')
		map->window = mlx_new_window(map->mlx, map->window_x, map->window_y, 
										"Burningship");
	if (map->c == 'f')
		map->window = mlx_new_window(map->mlx, map->window_x, map->window_y, 
										"Frog");
	map->itmax = 50;
	map->zoom = 1;
	map->colors = 0;
	map->deform = 1;
	return (1);
}
