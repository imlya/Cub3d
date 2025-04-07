/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:21:47 by imatek            #+#    #+#             */
/*   Updated: 2025/04/07 14:41:47 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	if (data->img[i].img)
	{
		destroy_texture(data, data->img, 0, 1);
		destroy_texture(data, data->img, 0, 1);
		free_ptr((void **)&data->img);
		i++;
	}
	if (data->assets)
		free_assets(data);
	if (data->window)
		mlx_destroy_window(data->mlx_ptr, data->window);
	// mlx_loop_end(data->mlx_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	// ne pas liberer manuellement mlx_ptr, destroy_display s'en occupe
	free_all(data);
	exit(EXIT_SUCCESS);
}

int	ft_loop(t_data *data)
{
	ft_draw_background(data);
	printf("coucou\n");
	ft_raycasting(data);
	ft_moves(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img[4].img, 0,
		0);
	return (0);
}

static void	ft_events_mlx(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &ft_loop, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, ft_keyrelease, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, ft_destroy,
		data);
	mlx_loop(data->mlx_ptr);
}

static void	ft_init_img(t_data *data)
{
	int	i;

	i = 0;
	data->img[0].path = data->north;
	data->img[1].path = data->south;
	data->img[2].path = data->east;
	data->img[3].path = data->west;
	while (i < 4)
	{
		data->img[i].img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img[i].path, &data->img[i].width, &data->img[i].height);
		if (!data->img[i].img)
		{
			// ft_destroy(data);
			ft_putendl_fd("mlx_xpm_file failed", 2);
		}
		i++;
	}
	data->img[4].img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	i = 0;
	while (i < 5)
	{
		data->img[i].pixels = mlx_get_data_addr(data->img[i].img,
				&data->img[i].bpp, &data->img[i].line_len,
				&data->img[i].endian);
		i++;
	}
}

void	ft_init_mlx(t_data *data)
{
	ft_init_player(data);
	ft_init_ray(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		ft_destroy(data);
		ft_putendl_fd("mlx_new_window failed", 2);
	}
	ft_init_img(data);
	ft_events_mlx(data);
}
