/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/04/01 17:52:12 by imatek           ###   ########.fr       */
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

void	ft_draw_player(t_data *data, int x, int y, int size, int color)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		ft_put_pixel(data, x + i, y, color);
		ft_put_pixel(data, x, y + i, color);
		ft_put_pixel(data, x + size, y + i, color);
		ft_put_pixel(data, x + i, y + size, color);
		i++;
	}
}

void	ft_clear_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_put_pixel(data, j, i, 0);
			j++;
		}
		i++;
	}
}
