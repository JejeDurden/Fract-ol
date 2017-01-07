/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:05:38 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 21:54:06 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void		ft_r(t_info *map)
{
	if (map->c == 'j')
		ft_julia_values(map);
	if (map->c == 'f')
		ft_frog_values(map);
	if (map->c == 'b')
		ft_burningship_values(map);
	if (map->c == 'm')
		ft_mandelbrot_values(map);
	if (map->c == 'B')
		ft_brain_values(map);
	if (map->c == 's')
		ft_star_values(map);
}

static void		ft_arrow_moves(int keycode, t_info *map)
{
	if (keycode == 123)
	{
		map->x1 -= 0.3;
		map->x2 -= 0.3;
	}
	if (keycode == 124)
	{
		map->x1 += 0.3;
		map->x2 += 0.3;
	}
	if (keycode == 125)
	{
		map->y1 += 0.3;
		map->y2 += 0.3;
	}
	if (keycode == 126)
	{
		map->y1 -= 0.3;
		map->y2 -= 0.3;
	}
}

int				ft_key_event(int keycode, t_info *map)
{
	mlx_clear_window(map->mlx, map->window);
	if (keycode == 53)
		exit(0);
	if (keycode == 31)
		map->deform++;
	if (keycode == 83)
		map->colors = 1;
	if (keycode == 84)
		map->colors = 2;
	if (keycode == 85)
		map->colors = 3;
	if (keycode == 69)
		map->itmax += 5;
	if (keycode == 78 && map->itmax > 10)
		map->itmax -= 5;
	if (keycode >= 123 && keycode <= 126)
		ft_arrow_moves(keycode, map);
	if (keycode == 15)
		ft_r(map);
	ft_expose_hook(map);
	return (1);
}
