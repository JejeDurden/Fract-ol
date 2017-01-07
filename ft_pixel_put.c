/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 13:46:11 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/05 09:14:33 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void		ft_pixel_put(t_info *map)
{
	map->data[(map->x * 4) + (map->y * map->window_x * 4)] = map->blue;
	map->data[(map->x * 4) + (map->y * map->window_x * 4) + 1] = map->green;
	map->data[(map->x * 4) + (map->y * map->window_x * 4) + 2] = map->red;
}
