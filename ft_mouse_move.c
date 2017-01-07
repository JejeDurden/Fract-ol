/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:19:46 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 19:54:57 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_mouse_move(int x, int y, t_info *map)
{
	if (map->deform % 2 == 0)
	{
		mlx_clear_window(map->mlx, map->window);
		if (x > 0 && x < map->window_x && y > 0 && y < map->window_y)
		{
			map->c_r = x / 1000.0;
			map->c_i = y / 1000.0;
		}
	}
	ft_expose_hook(map);
	return (1);
}
