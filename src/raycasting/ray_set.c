/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:52:05 by imatek            #+#    #+#             */
/*   Updated: 2025/04/03 19:08:16 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_ray_init(t_data *data)
{
	data->ray.dir_x = 0;
	data->ray.dir_y = 0;
	data->ray.camera_x = 0;
	data->ray.delta_dist_x = 0;
	data->ray.delta_dist_y = 0;
	data->ray.side_dist_x = 0;
	data->ray.side_dist_y = 0;
	data->ray.map_x = 0;
	data->ray.map_y = 0;
	data->ray.step_x = 1; // 0 nyny
	data->ray.step_y = 1; // 0 nyny
	data->ray.side = 0;
	data->ray.perpwalldist = 0;
	data->ray.line_height = 0;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
}

static void ft_set_step_and_side(t_data *data)
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.pos_x - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.pos_x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.pos_y - data->ray.map_y)
			* data->player.pos_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.pos_y)
			* data->player.pos_y;
	}
}

void	ft_ray_set(t_data *data, int i)
{
		data->ray.camera_x = 2 * i / (double)WIDTH - 1;
		data->ray.dir_x = data->player.dir_x + data->player.plane_x
			* data->ray.camera_x;
		data->ray.dir_y = data->player.dir_y + data->player.plane_y
			* data->ray.camera_x;
		data->ray.delta_dist_x = fabs(1 / data->ray.dir_x);
		data->ray.delta_dist_y = fabs(1 / data->ray.dir_y);
		data->ray.map_x = (int)data->player.pos_x;
		data->ray.map_y = (int)data->player.pos_y;
		ft_set_step_and_side(data);
}
