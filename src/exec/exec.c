/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:35:47 by imatek            #+#    #+#             */
/*   Updated: 2025/03/11 12:51:51 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_ray_direction(t_player *player)
{
	while (player->x < WIDTH)
	{
		double camera_x = 2 * player->x / (double)WIDTH - 1;
		double ray_dir_x = player->dir_x + player->plane_x * camera_x;
		double ray_dir_y = player->dir_y + player->plane_y * camera_x;
	}
}
