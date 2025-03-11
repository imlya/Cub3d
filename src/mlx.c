/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:47 by imatek            #+#    #+#             */
/*   Updated: 2025/03/11 12:45:45 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_put_pixel(t_img *image, int x, int y, int color)
{
	int	dest;

	dest = (y * image->line_len) + (x * (image->bpp / 8));
	*(unsigned int *)(dest + image->pixels) = color;
}

int	ft_destroy(t_data *data)
{
	if (data->image)
		mlx_destroy_image(data->mlx, data->image);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_keyboard(int keysym, t_data *data, t_player *player)
{
	if (keysym == XK_Escape)
		ft_destroy(data);
	if (keysym == 119)
		player->y -= (0.5);
	else if (keysym == 115)
		player->y += (0.5);
	else if (keysym == 97)
		player->x -= (0.5);
	else if (keysym == 100)
		player->x += (0.5);
	else if (keysym == XK_Right)
		player->x -= (0.5);
	else if (keysym == XK_Left)
		player->x += (0.5);
	return (0);
}

void	ft_events_mlx(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keyboard, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
}

void	ft_init_mlx(t_data *data, t_img *image)
{
	t_player	player;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_window failed", 2);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_image failed", 2);
	}
	image->pixels = mlx_get_data_addr(data->image, &image->bpp,
			&image->line_len, &image->endian);
	ft_events_mlx(data);
	init_data(data, &player);
}

// mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.
// wall_texture = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);