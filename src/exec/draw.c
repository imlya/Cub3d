/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:42:30 by imatek            #+#    #+#             */
/*   Updated: 2025/03/17 16:35:28 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel(t_img *image, int x, int y, int color)
{
	int	dest;

	dest = (y * image->line_len) + (x * (image->bpp / 8));
	*(unsigned int *)(dest + image->pixels) = color;
}

void	ft_draw_player(t_img *image, int x, int y, int size, int color)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		ft_put_pixel(image, x + i, y, color);
		ft_put_pixel(image, x, y + i, color);
		ft_put_pixel(image, x + size, y + i, color);
		ft_put_pixel(image, x + i, y + size, color);
		i++;
	}
}
