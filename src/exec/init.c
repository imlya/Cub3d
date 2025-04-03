/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/03 19:10:15 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_init_player(t_data *data)
{
	data->player.pos_x = 22; // 0 nyny
	data->player.pos_y = 12; // 0 nyny
	data->player.dir_x = -1; // 0 nyny
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66; // 0 nyny
	ft_player_dir(data);
	// data->player.time = 0;
	// data->player.old_time = 0;
	// data->player.up = false;
	// data->player.down = false;
	// data->player.right = false;
	// data->player.left = false;
	// data->player.rotate_right = false;
	// data->player.rotate_left = false;
}

void	ft_init_ray(t_data *data)
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
