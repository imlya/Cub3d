/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:47 by imatek            #+#    #+#             */
/*   Updated: 2025/03/17 17:16:44 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_destroy(data);
	if (keycode == KEY_W)
		data->player->up = true;
	else if (keycode == KEY_S)
		data->player->down = true;
	else if (keycode == KEY_D)
		data->player->right = true;
	else if (keycode == KEY_A)
		data->player->left = true;
	else if (keycode == KEY_RIGHT)
		data->player->rotate_right = true;
	else if (keycode == KEY_LEFT)
		data->player->rotate_left = true;
	return (0);
}

int	ft_keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_destroy(data);
	if (keycode == KEY_W)
		data->player->up = false;
	else if (keycode == KEY_S)
		data->player->down = false;
	else if (keycode == KEY_D)
		data->player->right = false;
	else if (keycode == KEY_A)
		data->player->left = false;
	else if (keycode == KEY_RIGHT)
		data->player->rotate_right = false;
	else if (keycode == KEY_LEFT)
		data->player->rotate_left = false;
	return (0);
}

void	ft_events_mlx(t_data *data)
{
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	// mlx_loop_hook(data->mlx, ft_move, data);
	mlx_loop(data->mlx);
}

void	ft_init_mlx(t_data *data, t_img *image)
{
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
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_image failed", 2);
	}
	image->pixels = mlx_get_data_addr(data->img, &image->bpp,
			&image->line_len, &image->endian);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	init_data(data);
}

// mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.
// wall_texture = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);