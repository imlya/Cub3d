/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:06:24 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/17 17:16:00 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_temp(t_data *data)
{
	data->temp->x = 0;
	data->temp->y = 0;
	data->temp->fd_map = -1;
	data->temp->map_check = NULL;
	data->temp->line = NULL;
}

void	init_player(t_player *player)
{
	player->pos_x = WIDTH / 2;
	player->pos_y = HEIGHT / 2;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->up = false;
	player->down = false;
	player->right = false;
	player->left = false;
	player->rotate_right = false;
	player->rotate_left = false;
}

void	init_data(t_data *data)
{
	t_player	player;

	init_player(&player);
	data->img->width = 0;
	data->img->height = 0;
	// data->max_x = 0;
	// data->max_y = 0;
	// data->img_x = 0;
	// data->img_y = 0;
	data->facing = 0;
	data->f_color = NULL;
	data->c_color = NULL;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	// data->sprite = NULL;
	data->map = NULL;
	data->temp = NULL;
}
