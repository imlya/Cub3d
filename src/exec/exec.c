/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:35:47 by imatek            #+#    #+#             */
/*   Updated: 2025/04/01 17:51:20 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_ray_position(t_data *data, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		data->player->camera_x = 2 * i / (double)WIDTH - 1;
		ray->dir_x = data->player->dir_x + data->player->plane_x
			* data->player->camera_x;
		ray->dir_y = data->player->dir_y + data->player->plane_y
			* data->player->camera_x;
		ray->delta_dist_x = fabs(1 / ray->dir_x);
		ray->delta_dist_y = fabs(1 / ray->dir_y);
		ray->map_x = data->player->pos_x;
		ray->map_y = data->player->pos_y;
		i++;
	}
}

void ft_calculate_step(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player->pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player->pos_y - ray->map_y)
			* data->player->pos_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player->pos_y)
			* data->player->pos_y;
	}
}
