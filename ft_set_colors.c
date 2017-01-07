/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:48:28 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 17:53:41 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void		ft_colors_0(t_info *map)
{
	if (map->i >= map->itmax - 35)
		ft_gradient_blue(map);
	else
		ft_degradient_blue(map);
}

void		ft_colors_1(t_info *map)
{
	if (map->i < map->itmax)
		ft_gradient_blue(map);
	else
		ft_black(map);
}

void		ft_colors_2(t_info *map)
{
	if (map->i >= map->itmax - 35)
		ft_gradient_weird(map);
	else
		ft_degradient_blue(map);
}

void	ft_set_colors(t_info *map)
{
	if (map->colors == 0)
		ft_colors_0(map);
	if (map->colors == 1)
		ft_colors_1(map);
	if (map->colors == 2)
		ft_colors_2(map);
}
