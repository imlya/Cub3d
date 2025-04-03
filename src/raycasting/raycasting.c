/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:35:47 by imatek            #+#    #+#             */
/*   Updated: 2025/04/03 18:24:37 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		// Check if ray has hit a wall
		if (data->map[data->ray.map_x][data->ray.map_y] > 0)
			hit = 1;
	}
}

static void	ft_wall_dist(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.side_dist_x
				- data->ray.delta_dist_x);
	else
		data->ray.perpwalldist = (data->ray.side_dist_y
				- data->ray.delta_dist_y);
	// Calculate height of line to draw on screen
	data->ray.line_height = (int)(HEIGHT / data->ray.perpwalldist);
	// calculate lowest and highest pixel to fill in current stripe
	data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_end >= HEIGHT)
		data->ray.draw_end = HEIGHT - 1;
}

void	ft_raycasting(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		ft_ray_set(data, i);
		ft_dda(data);
		ft_wall_dist(data);
		// ft_add_texture(data);
		i++;
	}
}
