/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:17:02 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 18:12:09 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void ft_button_1(t_info *map, int x, int y)
{
	float	tempx1;
	float	tempy1;

	tempx1 = map->x1;
	tempy1 = map->y1;
	map->x1 += (fabsf(map->x1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->x2 += (fabsf(tempx1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->y1 += (fabsf(map->y1 - map->y2) / map->window_y) *
		(y - map->window_y / 2) / map->zoom;
	map->y2 += (fabsf(tempy1 - map->y2) / map->window_y) *
		(y - map->window_y / 2) / map->zoom;
}
static void ft_button_4(t_info *map, int x, int y)
{
	float	tempx1;
	float	tempy1;

	map->zoom += 1;
	tempx1 = map->x1;
	tempy1 = map->y1;
	map->x1 += (fabsf(map->x1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->x2 += (fabsf(tempx1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->y1 += (fabsf(map->y1 - map->y2) / map->window_y) *
		(y - map->window_y / 2) / map->zoom;
	map->y2 += (fabsf(tempy1 - map->y2) / map->window_y) *
		(y - map->window_y / 2) / map->zoom;
}
static void ft_button_5(t_info *map, int x, int y)
{
	float	tempx1;
	float	tempy1;

	map->zoom -= 1;
	tempx1 = map->x1;
	tempy1 = map->y1;
	map->x1 += (fabsf(map->x1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->x1 += (fabsf(map->x1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->x2 += (fabsf(tempx1 - map->x2) / map->window_x) *
		(x - map->window_x / 2) / map->zoom;
	map->y1 += (fabsf(map->y1 - map->y2) / map->window_y) *
		(y - map->window_y / 2) / map->zoom;
	map->y2 += (fabsf(tempy1 - map->y2) / map->window_y) *
		(y - map->window_y / 2) / map->zoom;
}

int		ft_mouse_event(int button, int x, int y, t_info *map)
{
	mlx_clear_window(map->mlx, map->window);
	if (x > 0 && x < map->window_x && y > 0 && y < map->window_y)
	{
		if (button == 1)
			ft_button_1(map, x, y);
		if (button == 4)
			ft_button_4(map, x, y);
		if (button == 5 && map->zoom > 1)
			ft_button_5(map, x, y);
	}
	ft_expose_hook(map);
	return (1);
}
