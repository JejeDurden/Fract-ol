/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 18:23:42 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 21:59:46 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_expose_hook(t_info *map)
{
	if (map->c == 'm')
		ft_mandeldraw(map);
	if (map->c == 'j')
		ft_juliadraw(map);
	if (map->c == 'b')
		ft_burningdraw(map);
	if (map->c == 'f')
		ft_frogdraw(map);
	if (map->c == 'B')
		ft_braindraw(map);
	if (map->c == 's')
		ft_stardraw(map);
	return (1);
}
