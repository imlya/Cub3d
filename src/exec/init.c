/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/01 17:13:26 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_init_player(t_data *data)
{
	data->player = ft_calloc(1, sizeof (t_player));
	check_alloc(data->player, data);
	data->player->pos_x = 22;
	data->player->pos_y = 12;
	data->player->dir_x = -1;
	data->player->dir_y = 0;
	data->player->plane_x = 0;
	data->player->plane_y = 0.66;
	data->player->time = 0;
	data->player->old_time = 0;
	data->player->up = false;
	data->player->down = false;
	data->player->right = false;
	data->player->left = false;
	data->player->rotate_right = false;
	data->player->rotate_left = false;
}

// ! Make sure the camera plane is perpendicular to the direction
// !but you can change the length of it ???

void ft_init_ray(t_data *data)
{
	data->ray = ft_calloc(1, sizeof(t_ray));
	check_alloc(data->ray, data);
	data->ray->dir_x = 0;
	data->ray->dir_y = 0;
	data->ray->map_x = (int)(data->player->pos_x);
	data->ray->map_y = (int)(data->player->pos_y);
	data->ray->step_x = 1;
	data->ray->step_y = 1;
	data->ray->hit = 0;
	data->ray->side = 0;
	data->ray->perpwalldist = 0;
	data->ray->delta_dist_x = 0;
	data->ray->delta_dist_y = 0;
	data->ray->side_dist_x = 0;
	data->ray->side_dist_y = 0;
}
