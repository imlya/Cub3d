/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:47 by imatek            #+#    #+#             */
/*   Updated: 2025/03/10 12:42:06 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	// if (data->image)
	// 	mlx_destroy_image(data->mlx, data->image);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_keyboard(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_destroy(data);
	return (0);
}

void ft_events_mlx(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keyboard, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy, data);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx, 500, 500, "CUB");
	if (!data->window)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_window failed", 2);
	}
	ft_events_mlx(data);
}


// mlx_hook: Registers events.
// mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.
// mlx_put_image_to_window: Puts your image to the screen at the given coordinates.

