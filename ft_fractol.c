/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:47:03 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 21:53:23 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

static void		ft_brain_star(t_info *map, char *param)
{
	if (ft_strcmp("star", param) == 0)
	{
		map->c = 's';
		ft_star(map);
	}
	else if (ft_strcmp("brain", param) == 0)
	{
		map->c = 'B';
		ft_brain(map);
	}
}

int				ft_fractol(t_info *map, char *param)
{
	if (ft_strcmp("julia", param) == 0)
	{
		map->c = 'j';
		ft_julia(map);
	}
	else if (ft_strcmp("mandelbrot", param) == 0)
	{
		map->c = 'm';
		ft_mandelbrot(map);
	}
	else if (ft_strcmp("burningship", param) == 0)
	{
		map->c = 'b';
		ft_burningship(map);
	}
	else if (ft_strcmp("frog", param) == 0)
	{
		map->c = 'f';
		ft_frog(map);
	}
	else if (ft_strcmp("brain", param) == 0 || ft_strcmp("star", param) == 0)
		ft_brain_star(map, param);
	return (-1);
}
