/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/09 21:26:30 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_init_img(t_data *data)
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
			ft_putendl_fd("create img failed", 2);
			exit(EXIT_FAILURE);
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
		if (!data->img[i].pixels)
		{
			ft_putendl_fd("add img failed", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putendl_fd("mlx_init failed", 2);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->window)
	{
		ft_putendl_fd("mlx_new_window failed", 2);
		exit(EXIT_FAILURE);
	}
	ft_init_player(data);
	ft_init_ray(data);
	ft_set_player(data);
	ft_init_img(data);
	ft_events_mlx(data);
}
