/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdesmare <jdesmare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:34:13 by jdesmare          #+#    #+#             */
/*   Updated: 2017/01/07 21:47:12 by jdesmare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		main(int argc, char **argv)
{
	t_info	*map;

	if (!(map = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf <fractal_name> [julia | mandelbrot "
				"| frog | burningship | brain | star]\n"
				, 2);
		return (-1);
	}
	if (ft_fractol(map, argv[1]) == -1)
	{
		ft_putstr_fd("Usage : ./fdf <fractal_name> [julia | mandelbrot"
				"| frog | burningship | brain | star]\n"
				, 2);
		return (-1);
	}
	free(map);
	return (1);
}
