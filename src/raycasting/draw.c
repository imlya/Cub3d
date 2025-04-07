/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/04/07 11:03:34 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	int	dest;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dest = (y * data->img->line_len) + (x * (data->img->bpp / 8));
	*(unsigned int *)(dest + data->img->pixels) = color;
}

void	ft_draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			if (y < HEIGHT / 2)
				ft_put_pixel(data, x, y, RED_INT); // !a remplacer par c_color
			else
				ft_put_pixel(data, x, y, GREEN_INT); // !a remplacer par f_color
			x++;
		}
		x++;
	}
}
