/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 09:03:13 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 17:52:05 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void		ft_blue(t_info *map)
{
	map->red = 0;
	map->green = 0;
	map->blue = 255;
}

void		ft_red(t_info *map)
{
	map->red = 255;
	map->green = 0;
	map->blue = 0;
}

void		ft_white(t_info *map)
{
	map->red = 255;
	map->green = 255;
	map->blue = 255;
}

void		ft_gradient_weird(t_info *map)
{
	int		n;

	n = 0;
	ft_pink(map);
	while (n < map->i)
	{
		map->green += 35;
		map->blue -= 10;
		n++;
	}
}

void		ft_degradient_blue(t_info *map)
{
	int		n;

	n = 0;
	ft_black(map);
	while (n < map->i)
	{
		map->blue += 25;
		n++;
	}
}

void		ft_gradient_blue(t_info *map)
{
	int		n;

	n = 0;
	ft_white(map);
	while (n < map->i)
	{
		map->red -= 25;
		map->green -= 25;
		n++;
	}
}
